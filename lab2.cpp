#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


class interpreter{
public:
	int num;
	char  name;

	void setval(char name1, int val){
		this->num = val;
		this->name = name1;
	}

	int getval()
	{
		return this->num;
	}

	char getname()
	{
		return this->name;
	}

	template <class type> 
	type add(type num1, type num2)
	{
		//summing and saving result in variable "result" of same type as that of arguments 
		type result = num1 + num2;
		return result;
	}
	template <class type>
	type subtract(type num1, type num2)
	{
		//subtracting and saving result in variable "result" of same type as that of arguments 
		type result = num1 - num2;
		return result;
	}

	template <class type>
	type multiplying(type num1, type num2)
	{
		//multiplying and saving result in variable "result" of same type as that of arguments 
		type result = num1 * num2;
		return result;
	}

	template <class type>
	type divide(type num1, type num2)
	{
		//diciding and saving result in variable "result" of same type as that of arguments 
		type result = num1 / num2;
		return result;
	}

};



int main(){
	string line;
	int check = 0;
	int flag = 0;
	int i = 0;
	int c = 0;
	char array[20];
	interpreter obj1[5];
	int numb = 0;
	

	ifstream myfile("input.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))  //line by line reading from file
		{
			cout << line << '\n';
			char * pch = new char[line.length() + 1];
			strcpy(pch, line.c_str());
			char * p = strtok(pch, " ");       //tokenizing the line with space
			while (p != NULL)
			{
				cout << p << '\n';
				if (!strcmp(p,"let")){     //if token == let
					flag = 1;
				}
				if (flag == 1){
					if (isdigit(*p)){
						obj1[c].num = (int)(*p - '0');
						cout << "number= " << obj1[c].num << endl;
					}
					else if (!isdigit(*p)){
						if (*p == 'x' || *p == 'y' || *p == 'z'){   //variable
							obj1[c].name = *p;
							cout << "name= " << obj1[c].name << endl;
						}

					}
				} else{				// if arthematic operation
					if (*p == '='){
						check=1;
					}
					else if (isdigit(*p)){
						array[i] = *p ;
						cout << "  array in digit  " << array[i];
						i++;
					}
					else if (!isdigit(*p)){
						if (check == 0){
							obj1[c].name;		//variable before the = operation
						}
						else{			//what comes after =
							if (*p == 'x' || *p == 'y' || *p == 'z'){
								array[i] = *p;
								i++;
							}
							else if (*p == '+' || *p == '-' || *p == '*' || *p == '/'){
								array[i] = *p;
								i++;
							}
							
						}
					}

				}
				p = strtok(NULL, " ");
			}
			c++;
		}
	
		myfile.close();
	}
	else 
		cout << "Unable to open file";

	return 0;
}
