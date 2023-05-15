//  int main()
//  {
// 	 //base
// 	 // int fd = open("f1.txt", O_RDONLY);
// 	 // printf("----%s*\n", get_next_line(fd));
// 	 // printf("----%s*\n", get_next_line(fd));
// 	 // printf("----%s*\n", get_next_line(fd));
// 	 // printf("----%s*\n", get_next_line(fd));
// 	 //empty
// 	 // int fd = open("empty.txt", O_RDONLY);
// 	 // printf("----%s*\n", get_next_line(-1));
// 	 // printf("----%s*\n", get_next_line(1000));
// 	 // printf("----%s*\n", get_next_line(fd));
// 	 //1char

// 	 int fd = open("giant_line.txt", O_RDONLY);
// 	 char *str;
// 	 str = get_next_line(fd);
// 	 printf("%s$\n", str);
// 	 free(str);
// 	 str = get_next_line(fd);
// 	 printf("%s$\n", str);
// 	 free(str);
// 	 str = get_next_line(fd);
// 	 printf("%s$\n", str);
// 	 free(str);
// 	 str = get_next_line(fd);
// 	 printf("%s$\n", str);

// 	//  int fd = open("41_with_nl.txt", O_RDONLY);
// 	//  char *str;
// 	//  str = get_next_line(fd);
// 	//  printf("%s$\n", str);
// 	//  free(str);
// 	//  str = get_next_line(fd);
// 	//  printf("%s$\n", str);
// 	//  free(str);
// 	//  str = get_next_line(fd);
// 	//  printf("%s$\n", str);
// 	//  free(str);
// 	//  str = get_next_line(fd);
// 	//  printf("%s$\n", str);

// 	 free(str);
// 	 close(fd);
//  }

