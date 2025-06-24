#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <map>
#include <termios.h>



void print_prompt() {

    std::cout << "mysh> " << std::flush;
}

std::vector<std::string> split_input(const std::string& input) {
    std::stringstream ss(input);
    std::string token;
    std::vector<std::string>args;
    while(ss >> token) args.push_back(token);
    return args;
}
std::map<pid_t, std::string> jobs;

int main(){
      std::string input;
      
      signal(SIGINT, SIG_IGN);
      signal(SIGTSTP, SIG_IGN);
      
      while(true) {
	  print_prompt();
	  
	  std::getline(std::cin, input);
	  if (input.empty()) continue;
	  
	  if(input == "exit") break;
	  
	  std::vector<std::string> args = split_input(input);
	  
	  std::vector<char*> argv;
	  for(auto& arg : args) argv.push_back(&arg[0]);
	  argv.push_back(nullptr);
	  
	  
	  if( args[0]== "cd"){
	      const char* path;
	      if(args.size() < 2) {
		  path = getenv("HOME");
	      }
	      else{
		  path = args[1].c_str();
	      }
	      if (chdir(path) != 0) {
		  perror("cd failed");
	  }
	  continue;
      }
	  pid_t pid = fork();
	  if(pid == 0){
	      
	    tcsetpgrp(STDIN_FILENO, getpid());
	    signal(SIGINT, SIG_DFL);
	    signal(SIGTSTP, SIG_DFL);
    
            execvp(argv[0], argv.data());
            perror("execvp failed");
            exit(EXIT_FAILURE);
    

	      signal(SIGINT, SIG_DFL);
	      signal(SIGTSTP, SIG_DFL);
	      
	      execvp(argv[0], argv.data());
	      perror("execvp failed");
	      exit(EXIT_FAILURE);
	  }
	  else if(pid >0){
	      int status;
	    waitpid(pid, &status, WUNTRACED);
	    tcsetpgrp(STDIN_FILENO, getpid());  

		if (WIFSTOPPED(status)) {
		jobs[pid] = input;
		std::cout << "[Stopped] PID: " << pid << "\n";
}

	  }
	  else{
	      perror("fork failed");
	  }
      }
      
    
    
    return 0;
    }

