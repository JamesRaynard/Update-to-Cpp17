#include <iostream>

int main() 
{
	char c;
	int ws_count{0};
	
	const char *arr = "How much whitespace in\t here?";
	std::cout << "Text to process: \"" << arr << "\"" << '\n';
	
	for (int i = 0; arr[i]; ++i) {
		c = arr[i];
		switch (c) {  
		  case ' ':
			//[[fallthrough]];              // Fall through to next case - not a mistake!
		  case '\t':
			//[[fallthrough]];              // Fall through to next case - not a mistake!
		  case '\n':
			++ws_count;            
			break;
		}
	}
	
	std::cout << "This text contains " << ws_count << " whitespace characters\n";
}