#include <iostream>
#include <string>

using namespace std;

int main( int argc, char *argv[]) {

	struct arg_types {
		bool flag;
		string short_arg;
		string long_arg;
	};

	arg_types args[] = {
		{false, "-h", "--help"},
		{false, "-v", "--version"},
		{false, "-w", "--write"},
		{false, "-r", "--remove"},
		{false, "-o", "--open"}
	};

	for (int iargs = 0; iargs < argc; iargs++) {
		for (int num_arg = 0; num_arg < 5; num_arg++) {
			if (!args[num_arg].flag &&
				(!string(argv[iargs]).compare(args[num_arg].short_arg) || !string(argv[iargs]).compare(args[num_arg].long_arg))) {
				args[num_arg].flag = true;
				cout << "Parameter " << args[num_arg].short_arg <<  " or " << args[num_arg].long_arg << " is listed" << endl;
			}
		}
	}

	return 0;
}
