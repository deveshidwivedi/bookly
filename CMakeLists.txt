cmake_minimum_required(VERSION 3.13)
project(LibraryManagement)

# Headers Directory
include_directories(include)

# All Source Files
add_executable(
	bookly
	src/main.c
	src/user.c
	src/functions.c
	src/hashmap.c
	src/borrower_queue.c
	src/book_list.c
	src/book_tree.c
	src/book.c
	src/user_tree.c
)
