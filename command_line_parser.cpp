#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_AGE 200
// search for parameters passed as arguments
bool getCmdOption(int argc, const char* argv[], const std::string& option, std::string& parameter)
{
	 bool found_flag = false;
     for( int i = 0; i < argc; ++i)
     {
          std::string arg = argv[i];
          size_t found = arg.find(option);
          if( found!= std::string::npos)
          {
			   found_flag = true;
               parameter = arg.substr(found + option.size());
			   return found_flag;
          }
     }
     return found_flag;
}

// parse the command line arguments and assigns the corresponding variables
int main(int argc, const char** argv)
{
    if (argc < 3)
    {
        std::cerr << "    USAGE: " << argv[0] << " --name=Nino --age=25\n" << std::endl;
        return 1;
    }
    std::string name;

	if (!getCmdOption(argc, argv, "--name=", name))
	{ 
		std::cout << "    Error! No name provided!" << std::endl;
		return 1;
	}
    std::string age_str;
	if (!getCmdOption(argc, argv, "--age=", age_str))
	{ 
		std::cout << "    Error! No age provided!" << std::endl;
		return 1;
	}

    // convert strings to numbers
    int age;
	std::istringstream(age_str) >> age;

    // verify that numbers are different from zero
    if ((age < 0.1) || (age > MAX_AGE))
    {
        std::cout << "\n    Error! Please check your age!" << std::endl;
        return 1;
    }
	std::cout << "Hi " << name << ". I see you are " << age << " years old but you look much younger!" << std::endl;

    return 0;
}
