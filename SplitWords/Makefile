all: split_words split_words2

split_words: split_words.cpp
	$(CXX) -std=c++0x -o split_words split_words.cpp

split_words2: split_words2.cpp
	$(CXX) -std=c++0x -o split_words2 split_words2.cpp

test: split_words
	./split_words

test2: split_words2
	./split_words2
