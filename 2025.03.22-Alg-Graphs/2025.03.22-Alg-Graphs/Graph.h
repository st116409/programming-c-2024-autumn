#pragma once

struct Matrix {
	int v;
	int** data;
	Matrix(): v(0), data(nullptr)
	{}
	void free() {
		if (data != nullptr) {
			for (int i = 0; i < v; ++i) {
				delete[] data[i];
			}
			delete[] data;
			data = nullptr;
		}
	}
	void init(int v) {
		if (data != nullptr) {
			free();
		}
		this->v = v;
		data = new int* [v];
		for (int i = 0; i < v; ++i) {
			data[i] = new int[v] {0};
		}
	}
	int edgesfrom(int vertex)
	{
		int count = 0;
		for (int i = 0; i < v; ++i) {
			if (data[vertex - 1][i] != 0) {
				++count;
			}
		}
		return count;
	}
	
	int edges()
	{
		int count{ 0 };
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				if (data[i][j] != 0) {
					++count;
				}
			}
		}
		return count;
	}
};


class Graph {
	Matrix m;
public:
	
	Graph();
	Graph(const Graph& graph);
	~Graph();
	void readMatrix();
	void readAdjencyList();
	void readEdgeList();
	void printMatrix();
	void printAdjencyList();
	void printEdgeList();

};
