#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>
#include <future>

using namespace std;

//Strategy class to create our methods and variables
class Strategies
{
public:
	Strategies();
	~Strategies();

	void readFile(string file);
	bool compile();

	string line;
	string curr_word;
	vector<vector<string>> read_lines;

	int LASTOUTCOME;
	int ALLOUTCOMES_W = 0;
	int ALLOUTCOMES_X = 0;
	int ALLOUTCOMES_Y = 0;
	int ALLOUTCOMES_Z = 0;
	int ITERATIONS = 0;
	int MYSCORE = 0;
};

//Constructor
Strategies::Strategies()
{
}

//Deconstructor
Strategies::~Strategies()
{
}

//Child class of class Strategies
class Gang : public Strategies
{
public:
	Gang();
	~Gang();
	virtual bool compile();

	int LASTOUTCOME;
	int ALLOUTCOMES_A;
	int ALLOUTCOMES_B;
	int ALLOUTCOMES_C;
};

//Constructor
Gang::Gang()
{
}

//Deconstructor
Gang::~Gang()
{
}

//We iterate through the vector and begin to check the words
//from the file for syntax errors character by character
bool Gang::compile()
{
	int ptr = 3;
	bool isTrue = false;

	for (int i = 0; i < read_lines.size(); i++)
	{
		isTrue = false;
		if (isdigit(read_lines[i][0][0]))
		{
			if (read_lines[i].size() == 2)
			{
				if (read_lines[i][1] == "BETRAY" || read_lines[i][1] == "SILENCE" || read_lines[i][1] == "RANDOM")
				{
					isTrue = true;
				}
			}
			else if (read_lines[i].size() == 3)
			{
				if (read_lines[i][1] == "IF")
				{
					if (read_lines[i][2] == "GOTO")
					{
						if (isdigit(read_lines[i][2][0]))
						{
							isTrue = true;
						}
					}
				}
			}
			else if (read_lines[i].size() > 3)
			{
				if (read_lines[i][1] == "IF")
				{
					if (read_lines[i][2] == "ALLOUTCOMES_W" || read_lines[i][2] == "ALLOUTCOMES_X" || read_lines[i][2] == "ALLOUTCOMES_Y" || read_lines[i][2] == "ALLOUTCOMES_Z" || read_lines[i][2] == "ALLOUTCOMES_A" || read_lines[i][2] == "ALLOUTCOMES_B" || read_lines[i][2] == "ALLOUTCOMES_C" || read_lines[i][2] == "ITERATIONS" || read_lines[i][2] == "MYSCORE" || isdigit(read_lines[i][2][0]))
					{
						bool flag = true;
						while (read_lines[i][ptr] != "<" && read_lines[i][ptr] != ">" && read_lines[i][ptr] != "=" && flag == true)
						{
							flag = false;
							if (read_lines[i][ptr] == "+" || read_lines[i][ptr] == "-")
							{
								ptr++;
								if (read_lines[i][ptr] == "ALLOUTCOMES_W" || read_lines[i][ptr] == "ALLOUTCOMES_X" || read_lines[i][ptr] == "ALLOUTCOMES_Y" || read_lines[i][ptr] == "ALLOUTCOMES_Z" || read_lines[i][ptr] == "ALLOUTCOMES_A" || read_lines[i][ptr] == "ALLOUTCOMES_B" || read_lines[i][ptr] == "ALLOUTCOMES_C" || read_lines[i][ptr] == "ITERATIONS" || read_lines[i][ptr] == "MYSCORE" || isdigit(read_lines[i][ptr][0]))
								{
									flag = true;
								}
							}
							ptr++;
						}
						if (read_lines[i][ptr] == "<" && read_lines[i][ptr] == ">" && read_lines[i][ptr] == "=")
						{
							ptr++;
							if (read_lines[i][ptr] == "ALLOUTCOMES_W" || read_lines[i][ptr] == "ALLOUTCOMES_X" || read_lines[i][ptr] == "ALLOUTCOMES_Y" || read_lines[i][ptr] == "ALLOUTCOMES_Z" || read_lines[i][ptr] == "ALLOUTCOMES_A" || read_lines[i][ptr] == "ALLOUTCOMES_B" || read_lines[i][ptr] == "ALLOUTCOMES_C" || read_lines[i][ptr] == "ITERATIONS" || read_lines[i][ptr] == "MYSCORE" || isdigit(read_lines[i][ptr][0]))
							{
								bool flag = true;
								ptr++;
								while (read_lines[i][ptr] != "GOTO" && flag == true)
								{
									flag = false;
									if (read_lines[i][ptr] == "+" || read_lines[i][ptr] == "-")
									{
										ptr++;
										if (read_lines[i][ptr] == "ALLOUTCOMES_W" || read_lines[i][ptr] == "ALLOUTCOMES_X" || read_lines[i][ptr] == "ALLOUTCOMES_Y" || read_lines[i][ptr] == "ALLOUTCOMES_Z" || read_lines[i][ptr] == "ALLOUTCOMES_A" || read_lines[i][ptr] == "ALLOUTCOMES_B" || read_lines[i][ptr] == "ALLOUTCOMES_C" || read_lines[i][ptr] == "ITERATIONS" || read_lines[i][ptr] == "MYSCORE" || isdigit(read_lines[i][ptr][0]))
										{
											flag = true;
										}
									}
									ptr++;
								}
								if (read_lines[i][ptr] == "GOTO")
								{
									ptr++;
									if (isdigit(read_lines[i][ptr][0]))
									{
										isTrue = true;
									}
								}
							}
						}
					}
					else
					{
						if (read_lines[i][1] == "IF")
						{
							if (read_lines[i][2] == "LASTOUTCOME" || read_lines[i][2] == "W" || read_lines[i][2] == "X" || read_lines[i][2] == "Y" || read_lines[i][2] == "Z")
							{
								if (read_lines[i][3] == "=")
								{
									if (read_lines[i][4] == "W" || read_lines[i][4] == "X" || read_lines[i][4] == "Y" || read_lines[i][4] == "Z" || read_lines[i][4] == "LASTOUTCOME")
									{
										if (read_lines[i][5] == "GOTO")
										{
											if (isdigit(read_lines[i][6][0]))
											{
												isTrue = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return isTrue;
}

//Open txt file, reading line by line the characters within the txt file
void Strategies::readFile(string file)
{

	ifstream filename(file);

	try
	{
	if (filename.is_open())
	{
		while (getline(filename, line))
		{   
			
			vector<string> vec;	// Vector that holds the words(strings) from the file
			curr_word = "";
			int i = 0;
			char c;
			char previous_char = NULL;

			//Checking for whitespaces and if there is more than one 
			//next to each other keep the first and ignore the rest
			while (line[i])
			{
				c = line[i];
				if (islower(c))
				{
					c = toupper(c);
				}
				if (!isspace(c))
				{
					curr_word += c;
				}
				else
				{  
					if (!isspace(previous_char))
					{
						vec.push_back(curr_word);
						curr_word = "";
					}
				}
				previous_char = c;
				i++;
			}
			vec.push_back(curr_word);
			read_lines.push_back(vec);
		}
		filename.close();
	}
	}
	catch (...)
	{
		cout << "Unable to open file" << endl;
	}
}

//We iterate through the vector and begin to check the words
//from the file for syntax errors character by character
bool Strategies::compile()
{
	int ptr = 3;
	bool isTrue = false;

	for (int i = 0; i < read_lines.size(); i++)
	{
		isTrue = false;
		if (isdigit(read_lines[i][0][0]))	
		{
			if (read_lines[i].size() == 2)
			{
				if (read_lines[i][1] == "BETRAY" || read_lines[i][1] == "SILENCE" || read_lines[i][1] == "RANDOM")
				{
					isTrue = true;
				}
			}
			else if (read_lines[i].size() == 3)
			{
				if (read_lines[i][1] == "IF")
				{
					if (read_lines[i][2] == "GOTO")
					{
						if (isdigit(read_lines[i][2][0]))
						{
							isTrue = true;
						}
					}
				}
			}
			else if (read_lines[i].size() > 3)
			{
				if (read_lines[i][1] == "IF")
				{
					if (read_lines[i][2] == "ALLOUTCOMES_W" || read_lines[i][2] == "ALLOUTCOMES_X" || read_lines[i][2] == "ALLOUTCOMES_Y" || read_lines[i][2] == "ALLOUTCOMES_Z" || read_lines[i][2] == "ITERATIONS" || read_lines[i][2] == "MYSCORE" || isdigit(read_lines[i][2][0]))
					{
						bool flag = true;
						while (read_lines[i][ptr] != "<" && read_lines[i][ptr] != ">" && read_lines[i][ptr] != "=" && flag == true)
						{
							flag = false;
							if (read_lines[i][ptr] == "+" || read_lines[i][ptr] == "-")
							{
								ptr++;
								if (read_lines[i][ptr] == "ALLOUTCOMES_W" || read_lines[i][ptr] == "ALLOUTCOMES_X" || read_lines[i][ptr] == "ALLOUTCOMES_Y" || read_lines[i][ptr] == "ALLOUTCOMES_Z" || read_lines[i][ptr] == "ITERATIONS" || read_lines[i][ptr] == "MYSCORE" || isdigit(read_lines[i][ptr][0]))
								{
									flag = true;
								}
							}
							ptr++;
						}
						if (read_lines[i][ptr] == "<" && read_lines[i][ptr] == ">" && read_lines[i][ptr] == "=")
						{
							ptr++;
							if (read_lines[i][ptr] == "ALLOUTCOMES_W" || read_lines[i][ptr] == "ALLOUTCOMES_X" || read_lines[i][ptr] == "ALLOUTCOMES_Y" || read_lines[i][ptr] == "ALLOUTCOMES_Z" || read_lines[i][ptr] == "ITERATIONS" || read_lines[i][ptr] == "MYSCORE" || isdigit(read_lines[i][ptr][0]))
							{
								bool flag = true;
								ptr++;
								while (read_lines[i][ptr] !="GOTO" && flag == true)
								{
									flag = false;
									if (read_lines[i][ptr] == "+" || read_lines[i][ptr] == "-")
									{
										ptr++;
										if (read_lines[i][ptr] == "ALLOUTCOMES_W" || read_lines[i][ptr] == "ALLOUTCOMES_X" || read_lines[i][ptr] == "ALLOUTCOMES_Y" || read_lines[i][ptr] == "ALLOUTCOMES_Z" || read_lines[i][ptr] == "ITERATIONS" || read_lines[i][ptr] == "MYSCORE" || isdigit(read_lines[i][ptr][0]))
										{
											flag = true;
										}
									}
									ptr++;
								}
								if (read_lines[i][ptr] == "GOTO")
								{
									ptr++;
									if (isdigit(read_lines[i][ptr][0]))
									{
										isTrue = true;
									}
								}
							}
						}
					}
					else
					{
						if (read_lines[i][1] == "IF")
						{
							if (read_lines[i][2] == "LASTOUTCOME" || read_lines[i][2] == "W" || read_lines[i][2] == "X" || read_lines[i][2] == "Y" || read_lines[i][2] == "Z")
							{
								if (read_lines[i][3] == "=")
								{
									if (read_lines[i][4] == "W" || read_lines[i][4] == "X" || read_lines[i][4] == "Y" || read_lines[i][4] == "Z" || read_lines[i][4] == "LASTOUTCOME")
									{
										if (read_lines[i][5] == "GOTO")
										{
											if (isdigit(read_lines[i][6][0]))
											{
												isTrue = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return isTrue;
}

//Interpreter class to create our methods and variables
class Interpreter
{
public:
	Interpreter();
	~Interpreter();

	int interpret(vector<vector<string>> read_lines, int n_lines, Strategies st);
	int prison(Strategies& st1, Strategies& st2);
	int line_finder(vector<vector<string>> read_lines, int l_lines);
};

//Constructor
Interpreter::Interpreter()
{
}

//Deconstructor
Interpreter::~Interpreter()
{
}

// Method to interpret the strategies and return 1 for betray and 0 for silence
//and when the number after GOTO is found check the lines again until it finds the correct number
int Interpreter::interpret(vector<vector<string>> read_lines, int n_lines, Strategies st)
{
	int var = 2;
	int left_side = 0;
	int right_side = 0;
	int i = n_lines;
	string comp = "";
	if (read_lines[i].size() == 2)
	{
		if (read_lines[i][1] == "BETRAY")
		{
			return 1;
		}
		else if (read_lines[i][1] == "SILENCE")
		{
			return 0;
		}
		else if (read_lines[i][1] == "RANDOM")
		{
			return rand() % 2;
		}
	}
	else if (read_lines[i].size()  > 2)
	{
		if (read_lines[i][1] == "IF")
		{
			if (read_lines[i][2] == "LASTOUTCOME" || read_lines[i][2] == "W" || read_lines[i][2] == "X" || read_lines[i][2] == "Y" || read_lines[i][2] == "Z")
			{
				if (read_lines[i][3] == "=")
				{
					if (read_lines[i][4] == "W" || read_lines[i][4] == "X" || read_lines[i][4] == "Y" || read_lines[i][4] == "Z" || read_lines[i][4] == "LASTOUTCOME")
					{
						if (read_lines[i][5] == "GOTO")
						{
							if (isdigit(read_lines[i][6][0]))
							{
								return interpret(read_lines, line_finder(read_lines, stoi(read_lines[i][6])),st);
							}
						}
					}
				}
			}
			else
			{
				if (read_lines[i][var] == "ALLOUTCOMES_W")
				{
					left_side += st.ALLOUTCOMES_W;
				}
				else if (read_lines[i][var] == "ALLOUTCOMES_X")
				{
					left_side += st.ALLOUTCOMES_X;
				}
				else if (read_lines[i][var] == "ALLOUTCOMES_Y")
				{
					left_side += st.ALLOUTCOMES_Y;
				}
				else if (read_lines[i][var] == "ALLOUTCOMES_Z")
				{
					left_side += st.ALLOUTCOMES_Z;
				}
				else if (read_lines[i][var] == "ITERATIONS")
				{
					left_side += st.ITERATIONS;
				}
				else if (read_lines[i][var] == "MYSCORE")
				{
					left_side += st.MYSCORE;
				}
				else if (isdigit(read_lines[i][var][0]))
				{
					left_side += stoi(read_lines[i][var]);
				}
				var++;
				while (read_lines[i][var] != "<" && read_lines[i][var] != ">" && read_lines[i][var] != "=")
				{
					int oper = 1;
					if (read_lines[i][var] == "+" || read_lines[i][var] == "-")
					{
						if (read_lines[i][var] == "-")
						{
							oper = -1;
						}
						var++;
						if (read_lines[i][var] == "ALLOUTCOMES_W")
						{
							left_side += oper*st.ALLOUTCOMES_W;
						}
						else if (read_lines[i][var] == "ALLOUTCOMES_X")
						{
							left_side += oper*st.ALLOUTCOMES_X;
						}
						else if (read_lines[i][var] == "ALLOUTCOMES_Y")
						{
							left_side += oper*st.ALLOUTCOMES_Y;
						}
						else if (read_lines[i][var] == "ALLOUTCOMES_Z")
						{
							left_side += oper*st.ALLOUTCOMES_Z;
						}
						else if (read_lines[i][var] == "ITERATIONS")
						{
							left_side += oper*st.ITERATIONS;
						}
						else if (read_lines[i][var] == "MYSCORE")
						{
							left_side += oper*st.MYSCORE;
						}
						else if (isdigit(read_lines[i][var][0]))
						{
							left_side += oper*stoi(read_lines[i][var]);
						}
					}
					var++;
				}
				if (read_lines[i][var] == "<" || read_lines[i][var] == ">" || read_lines[i][var] == "=")
				{
					comp = read_lines[i][var];
					var++;
					if (read_lines[i][var] == "ALLOUTCOMES_W")
					{
						left_side += st.ALLOUTCOMES_W;
					}
					else if (read_lines[i][var] == "ALLOUTCOMES_X")
					{
						left_side += st.ALLOUTCOMES_X;
					}
					else if (read_lines[i][var] == "ALLOUTCOMES_Y")
					{
						left_side += st.ALLOUTCOMES_Y;
					}
					else if (read_lines[i][var] == "ALLOUTCOMES_Z")
					{
						left_side += st.ALLOUTCOMES_Z;
					}
					else if (read_lines[i][var] == "ITERATIONS")
					{
						left_side += st.ITERATIONS;
					}
					else if (read_lines[i][var] == "MYSCORE")
					{
						left_side += st.MYSCORE;
					}
					else if (isdigit(read_lines[i][var][0]))
					{
						left_side += stoi(read_lines[i][var]);
					}
					var++;
					while (read_lines[i][var] != "GOTO")
					{
						int oper = 1;
						if (read_lines[i][var] == "+" || read_lines[i][var] == "-")
						{
							if (read_lines[i][var] == "-")
							{
								oper = -1;
							}
							var++;
							if (read_lines[i][var] == "ALLOUTCOMES_W")
							{
								right_side += oper*st.ALLOUTCOMES_W;
							}
							if (read_lines[i][var] == "ALLOUTCOMES_X")
							{
								right_side += oper*st.ALLOUTCOMES_X;
							}
							if (read_lines[i][var] == "ALLOUTCOMES_Y")
							{
								right_side += oper*st.ALLOUTCOMES_Y;
							}
							if (read_lines[i][var] == "ALLOUTCOMES_Z")
							{
								right_side += oper*st.ALLOUTCOMES_Z;
							}
							if (read_lines[i][var] == "ITERATIONS")
							{
								right_side += oper*st.ITERATIONS;
							}
							if (read_lines[i][var] == "MYSCORE")
							{
								right_side += oper*st.MYSCORE;
							}
							if (isdigit(read_lines[i][var][0]))
							{
								right_side += oper*stoi(read_lines[i][var]);
							}
						}
						var++;
					}
					if (read_lines[i][var] == "GOTO")
					{
						var++;
						if (isdigit(read_lines[i][var][0]))
						{
							if ((comp == "<" && left_side < right_side) || (comp == "=" && left_side == right_side) || (comp == ">" && left_side > right_side))
								return interpret(read_lines, line_finder(read_lines, stoi(read_lines[i][var])),st);
							else
								return interpret(read_lines, i + 1, st);
						}
					}
				}
			}
		}
	}
}

//Here the two prisoners are created and we calculate how
//many years each prisoner will get
int Interpreter::prison(Strategies& st1, Strategies& st2)
{
	for (int i = 0; i < 200; i++)
	{
		future<int> t1 = async(&Interpreter::interpret, this, st1.read_lines, 0, st1);	//Retrieves a value from a provider object
		future<int> t2 = async(&Interpreter::interpret, this, st2.read_lines, 0, st2);	//and creates a new thread to call interpret

		int pr1 = t1.get();
		int pr2 = t2.get();

		if (pr1 == 0)
		{
			if (pr2 == 0)
			{
				st1.MYSCORE += 2;
				st2.MYSCORE += 2;
				st1.ALLOUTCOMES_W++;
				st2.ALLOUTCOMES_W++;
			}
		}
		if (pr1 == 0)
		{
			if (pr2 == 1)
			{
				st1.MYSCORE += 5;
				st2.MYSCORE += 0;
				st1.ALLOUTCOMES_X++;
				st2.ALLOUTCOMES_Y++;
			}
		}
		if (pr1 == 1)
		{
			if (pr2 == 0)
			{
				st1.MYSCORE += 0;
				st2.MYSCORE += 5;
				st1.ALLOUTCOMES_Y++;
				st2.ALLOUTCOMES_X++;
			}
		}
		if (pr1 == 1)
		{
			if (pr2 == 1)
			{
				st1.MYSCORE += 4;
				st2.MYSCORE += 4;
				st1.ALLOUTCOMES_Z++;
				st2.ALLOUTCOMES_Z++;
			}
		}
		st1.ITERATIONS++;
		st2.ITERATIONS++;
	}
	return 0;
}

//Method that checks the lines in order to find the line 
//that the GOTO number was pointing at
int Interpreter::line_finder(vector<vector<string>> read_lines, int l_lines)
{
	for (int i = 0; i<read_lines.size(); i++)
	{
		if (stoi(read_lines[i][0]) == l_lines)
			return i;
	}
	return 0;
}

int main()
{

	Strategies* s1 = new Strategies;
	Strategies* s2 = new Strategies;
	Interpreter a;
	
	int n_files = 0;

	cout << "How many files you want to run?" << endl;
	cin >> n_files;
	
	int score[10] = { 0 };
	srand(time(NULL));
	try
	{
		// Lambda funtion
		auto init = [](Strategies * s1) -> void {s1->MYSCORE = 0; s1->ALLOUTCOMES_W = 0; s1->ALLOUTCOMES_X = 0; s1->ALLOUTCOMES_Z = 0; s1->ALLOUTCOMES_Y = 0; s1->ITERATIONS = 0; };

		string f_arr[10] = { "Strategies/S1.txt", "Strategies/S2.txt", "Strategies/S3.txt", "Strategies/S4.txt", "Strategies/S5.txt", "Strategies/S6.txt", "Strategies/S7.txt" ,"Strategies/S8.txt", "Strategies/S9.txt", "Strategies/S10.txt" };
		for (int i = 0; i < n_files; i++)
		{
			Strategies* s1 = new Strategies;
			s1->readFile(f_arr[i]);
			s1->compile();
			for (int j = i + 1; j < n_files; j++)
			{
				Strategies* s2 = new Strategies;
				s2->readFile(f_arr[j]);
				s2->compile();
				a.prison(*s1, *s2);
				score[i] += s1->MYSCORE;
				score[j] += s2->MYSCORE;
				init(s1);
				delete s2;
			}
			delete s1;
		}

		//Check if there is already a result txt file,
		//delete it if there is and create a new file to hold the new output
		ofstream myfile;
		if (remove("Strategies/Result.txt") != 0)
			perror("Error deleting file");
		else
			puts("File successfully deleted: Creating new file");

		myfile.open("Strategies/Result.txt");

		for (int i = 0; i < n_files; i++)
		{
			myfile << "Prisoner's " << i << " average years after 200 iterations: " << score[i] / n_files << endl;
			cout << "Prisoner's " << i << " average years after 200 iterations: " << score[i] / n_files << endl;
		}
		myfile.close();
	}
	catch (...)
	{
		cout << "Error: Can only take up to 10 files!" << endl;
	}
	system("pause");

	return 0;
}