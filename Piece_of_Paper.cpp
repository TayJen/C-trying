#include "Piece_of_Paper.h"
#include <iostream>
#include <string>

Piece_of_paper::Piece_of_paper() {
	printf("Piece_of_paper()\n");
	size = 0;
	material = 0;
}
Piece_of_paper::Piece_of_paper(int size_, char material_ = 'w') {
	printf("Piece_of_paper(int size_, char material_)\n");
	size = size_;
	material = material_;
}
Piece_of_paper::Piece_of_paper(const Piece_of_paper& a) {
	printf("Piece_of_paper(const Piece_of_paper& a)\n");
	size = a.size;
	material = a.material;
}
Piece_of_paper::~Piece_of_paper() {
	printf("~Piece_of_paper(%d, %c)\n", size, material);
}
void Piece_of_paper::make_smaller() {
	if (size > 1)
		size--;
	else
		printf("It is already the smallest");
}
std::string Piece_of_paper::classname() {
	return "Piece_of_paper";
}

Book::Book() : Piece_of_paper() {
	printf("Book()");
	page_count = 0;
	genre = 0;
}
Book::Book(int page_count_, int genre_, int size_ = 4, char material_ = 'w')
	: Piece_of_paper(size_, material_)
{
	printf("Book(int page_count_, int genre_, int size_ = 4, char material_ = 'w')");
	page_count = page_count_;
	genre = genre_;
}
Book::Book(const Book& a)
	: Piece_of_paper(a)
{
	printf("Book(const Book& a)");
	page_count = a.page_count;
	genre = a.genre;
}
Book::~Book() {
	printf("~Book(%d, %c, %d, %d)", size, material, page_count, genre);
}
void Book::add() {
	page_count++;
}
std::string Book::classname() {
	return "Book";
}

Album::Album() : Piece_of_paper() {
	printf("Album()");
	number_of_paintings = 0;
}
Album::Album(int number_of_paintings_, int size_ = 3, char material_ = 'w')
	: Piece_of_paper(size_, material_) {
	printf("Album(int number_of_paintings_, int size_ = 3, char material_ = 'w')");
	number_of_paintings = number_of_paintings_;
}
Album::Album(const Album& a)
	: Piece_of_paper(a) {
	printf("Album(const Album& a)");
	number_of_paintings = a.number_of_paintings;
}
Album::~Album() {
	printf("~Album(%d, %c, %d)", size, material, number_of_paintings);
}
void Album::add() {
	number_of_paintings++;
}
std::string Album::classname() {
	return "Album";
}
