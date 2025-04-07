#include "Graph.h"
#include <iostream>

Graph::Graph()
{
	this->m = Matrix();
}

Graph::Graph(const Graph& graph)
{
	m.init(graph.m.v);
	for (int i = 0; i < m.v; ++i) {
		for (int j = 0; j < m.v; ++j) {
			m.data[i][j] = graph.m.data[i][j];
		}
	}
}

Graph::~Graph()
{
	m.free();
}

void Graph::readMatrix()
{
	int v = 0;
	std::cin >> v;
	m.init(v);
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			std::cin >> m.data[i][j];
		}
	}
}

void Graph::readAdjencyList()
{
	int v = 0;
	std::cin >> v;
	m.init(v);
	for (int i = 0; i < v; ++i) {
		int e = 0;
		std::cin >> e;
		for (int j = 0; j < e; ++j) {
			int to = 0;
			std::cin >> to;
			m.data[i][to - 1] = 1;
		}
	}

}

void Graph::readEdgeList()
{
	int v = 0;
	int e = 0;
	std::cin >> v >> e;
	m.init(v);
	for (int i = 0; i < e; ++i) {
		int from = 0;
		int to = 0;
		std::cin >> from >> to;
		m.data[from - 1][to - 1] = 1;
	}
}

void Graph::printMatrix()
{
	std::cout << m.v << "\n";
	for (int i = 0; i < m.v; ++i) {
		for (int j = 0; j < m.v; ++j) {
			std::cout << m.data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::printAdjencyList()
{
	std::cout << m.v << "\n";
	for (int i = 0; i < m.v; ++i) {
		std::cout << m.edgesfrom(i + 1) << " ";
		for (int j = 0; j < m.v; ++j) {
			if (m.data[i][j] != 0) {
				std::cout << j + 1 << " ";
			}
			
		}
		std::cout << "\n";
	}
}

void Graph::printEdgeList()
{
	std::cout << m.v << " " << m.edges() << "\n";
	for (int i = 0; i < m.v; ++i) {
		for (int j = 0; j < m.v; ++j) {
			if (m.data[i][j] != 0) {
				std::cout << i + 1 << " " << j + 1 << "\n";
			}
		}
	}
}

