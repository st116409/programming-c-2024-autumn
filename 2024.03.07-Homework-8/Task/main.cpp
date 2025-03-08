#include <iostream>

class ArrayList {
	int len;
	int* data;
	
	void init(int len = 10) {
		this->len = len;
		data = (int*)malloc(sizeof(int) * len);
	}
	
	bool indexValid(int index)
	{
		return 0 <= index && index < this->len;
	}

	void expand(bool front = false) {
		++len;
		int* p = (int*)malloc(sizeof(int) * len);

		for (int i = 0; i < len - 1; ++i) {
			p[i + front] = this->data[i];
		}
		free(this->data);
		this->data = p;
	}
public:
	
	ArrayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}

	ArrayList(ArrayList& list)
	{
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		free(this->data);
		this->data = nullptr;
		this->len = 0;
	}
	
	void randomize(int min=  0, int max = 99) {
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}

	void print(){
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;

	}

	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}

	int count()
	{
		return len;
	}

	void pushback(int el) {
		this->expand(0);
		this->set(len - 1, el);
	}

	void pushfront(int el) {
		this->expand(1);
		this->set(0, el);
	}

	void insert(int index, int el) {
		if (indexValid(index)) {
			this->expand(0);
			for (int i = len - 1; i > index; --i) {
				this->data[i] = this->data[i - 1];
			}
			this->data[index] = el;
		}
	}

	void extract(int index) {
		if (indexValid(index)) {
			--len;
			int* p = (int*)malloc(sizeof(int) * len);

			int j = 0;
			for (int i = 0; i < len; ++i) {
				if (i == index) ++j;
				p[i] = this->data[i + j];
			}
			free(this->data);
			this->data = p;
		}
	}

	void popfront() {
		this->extract(len - 1);
	}
	void popback() {
		this->extract(0);
	}

	void reverse(int start, int end) {
		if (0 <= start && start <= end && end < len) {
			int range = end - start + 1;
			int* p = (int*)malloc(sizeof(int) * range);
			for (int i = 0; i < range; i++) {
				p[i] = this->data[start + i];
			}
			for (int i = 0; i < range; i++) {
				this->data[start + i] = p[range - 1 - i];
			}
			free(p);
		}
	}

	int sum() {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum+=this->data[i];
		}
		return sum;
	}

	int secondMax() {
		int max1 = this->data[0];
		int max2 = this->data[0];

		for (int i = 0; i < len; ++i) {
			if (this->data[i] > max1) {
				max2 = max1;
				max1 = this->data[i];
			}
		}
		return max2;
	}

	int lastMiIndex() {
		int min = this->data[0];
		int index = 0;

		for (int i = 1; i < len; ++i) {
			if (this->data[i] <= min) {
				min = this->data[i];
				index = i;
			}
		}
		return index;
	}
	void shift(int k) {
		int* p = (int*)malloc(sizeof(int) * len);

		for (int i = 0; i < len; ++i) {
			p[(k + i) % len] = this->data[i];
		}
		free(this->data);
		this->data = p;
	}

	int countOdd() {
		int count = 0;
		for (int i = 0; i < len; i++) {
			if (this->data[i] % 2 == 1) {
				++count;
			}
		}
		return count;
	}

	int sumEven() {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			if (this->data[i] % 2 == 0) {
				sum += this->data[i];
			}
		}
		return sum;
	}
};


int main(int argc, char* argv[]) {

	ArrayList m(8);
	m.randomize();
	m.print();
	m.reverse(4,8);
	m.extract(-1);
	m.print();
	std::cout << m.sumEven();

	return EXIT_SUCCESS;
}