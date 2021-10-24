# Exam-02 42 :page_with_curl:

This is my version of printf for exam-02.

Don't forget to compile with Wflags and fsanitize for the leaks:
> gcc -g -Wall -Wextra -Werror -fsanitize=address main.c printf.c && ./a.out