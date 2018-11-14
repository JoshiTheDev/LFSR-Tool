#include<iostream>
#include<array>
#include<vector>

int bit_xor(int x, int y);

int main()
{
	std::array<int, 8> initial_values { 1,0,0,0,0,1,0,1 };
	std::vector<int> si;

	std::array temp = initial_values;
	std::array result = initial_values;

	int seq_counter = 0;

	//print out initial value + add to si
	std::cout << '[';
	for (int i = 0; i <= 7; i++)
		std::cout << initial_values[i];
	std::cout << "] " << seq_counter++ << std::endl;
	si.push_back(initial_values[7]);

	do 
	{
		//save the predecessor
		temp = result;

		//s6⊕s5⊕s1⊕s0 into the first flip-flop(s7)
		result[0] = bit_xor(bit_xor(result[1], result[2]), bit_xor(result[6], result[7]));

		std::cout << '[' << result[0];
		//shift the bits
		for(int i = 1; i <= 7; i++)
		{
			result[i] = temp[i - 1];
			std::cout << result[i];

			//add to si
			if (i == 7 && seq_counter < 89)
				si.push_back(result[i]);

		}
		std::cout << "] " << seq_counter << std::endl;

		//increase counter
		seq_counter++;

	} while (result != initial_values);

	std::cout << std::endl << "Si binary: ";

	for (int i = 0; i < si.size(); i++)
		std::cout << si.at(i);

	int a;
	std::cin >> a;
}



inline int bit_xor(int x, int y) 
{

	return (x + y) % 2;

}