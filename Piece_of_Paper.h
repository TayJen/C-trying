#pragma once
#include <string>
class Piece_of_paper {
protected:
	int size; 
	char material;
public:
	Piece_of_paper();
	Piece_of_paper(int size_, char material_ = 'w');
	Piece_of_paper(const Piece_of_paper& a);
	virtual ~Piece_of_paper();
	void make_smaller();
	virtual void add() = 0;
	virtual std::string classname();
};

class Book : Piece_of_paper {
private:
	int page_count, genre;
public:
	Book();
	Book(int page_count_, int genre_, int size_ = 4, char material_ = 'w');
	Book(const Book& a);
	~Book();
	void add();
	virtual std::string classname();
};

class Album : Piece_of_paper {
private:
	int number_of_paintings;
public:
	Album();
	Album(int number_of_paintings_, int size_ = 3, char material_ = 'w');
	Album(const Album& a);
	~Album();
	void add();
	virtual std::string classname();
};