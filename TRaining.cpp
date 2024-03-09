#include<iostream>
#include<vector>
class fracnumbers
{
public:
	int numerator = 0;
	int denominator = 0;
 
	fracnumbers(int a, int b) {
		numerator = a;
		denominator = b;
	}

};
void find_greatest_common_divisor() {
	int n, num;
	std::cout << "Enter the number of elements to find the GCD : ";
	std::cin >> n;
	std::vector<int>nums;
	std::cout << "Enter elements : ";
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		nums.push_back(num);
	}
	for (int i = 0; i < n - 1; i++) {
		while (nums[i] != 0 && nums[i + 1] != 0) {
			if (nums[i] > nums[i + 1]) {
				nums[i] %= nums[i + 1];
			}
			else {
				nums[i + 1] %= nums[i];
			}
		}
		if (nums[i] != 0) {
			nums[i + 1] = nums[i];
		}
	}
	std::cout << "GCD :" << nums[n-1]<<"\n";
}

void find_gcd_of_fractional_numbers(){
	int n,c,d;
	std::vector<fracnumbers>nums;
	std::cout << "Enter the number of elements to find the GCD : ";
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		std::cout << "Enter numerator : ";
		std::cin >> c;
		std::cout << "Enter denominator : ";
		std::cin >> d;
		nums.push_back(fracnumbers(c, d));
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		a = nums[i].denominator;
		b = nums[i+1].denominator;
		while (nums[i].denominator != 0 && nums[i + 1].denominator != 0) {
			if (nums[i].denominator > nums[i + 1].denominator) {
				nums[i].denominator %= nums[i + 1].denominator;
			}
			else {
				nums[i + 1].denominator %= nums[i].denominator;
			}
		}
		if (nums[i].denominator != 0) {
			nums[i + 1].denominator = a*b/nums[i].denominator;
		}
		else {
			nums[i + 1].denominator = a * b / nums[i+1].denominator;
		}
	}
	std::cout << "SCM of denominators :" << nums[n - 1].denominator<<"\n";
	for (int i = 0; i < n - 1; i++) {
		nums[i].numerator *= nums[n - 1].denominator;
		nums[i].denominator = nums[n - 1].denominator;
	}
	for (int i = 0; i < n - 1; i++) {
		while (nums[i].numerator != 0 && nums[i + 1].numerator != 0) {
			if (nums[i].numerator > nums[i + 1].numerator) {
				nums[i].numerator %= nums[i + 1].numerator;
			}
			else {
				nums[i + 1].numerator %= nums[i].numerator;
			}
		}
		if (nums[i].numerator != 0) {
			nums[i + 1].numerator = nums[i].numerator;
		}
	}
	std::cout << "GCD :" << nums[n - 1].numerator<<"/"<< nums[n - 1].denominator;
}


int main() {
	find_greatest_common_divisor();
	find_gcd_of_fractional_numbers();
}