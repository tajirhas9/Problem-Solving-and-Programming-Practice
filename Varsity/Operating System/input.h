void inp(int n) {
	std::fstream input;
	input.open("input.txt",std::ios::out|std::ios::trunc);

	for(int i = 1; i <= n; ++i)
		input << i << " ";
	input << std::endl;
}

void ask() {
	int ck;

	std::cout << "Do you want to change limit?" << std::endl;

	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;

	std::cin >> ck;

	if(ck == 1) {
		
		int n;

		std::cout << "Type your range : ";
		std::cin >> n;

		inp(n);
	}

}