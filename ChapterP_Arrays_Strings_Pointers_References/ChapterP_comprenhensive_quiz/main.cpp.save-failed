#include <algorithm>
#include <iostream>
#include <array>
#include <numeric> // for std::reduce
#include <string>
#include <vector>

// We want to use Item types to index an array.
enum ItemTypes
{
    ITEM_HEALTH_POTION,
    ITEM_TORCH,
    ITEM_ARROW,
    MAX_ITEMS,
};

int countTotalItems(std::array<int,ItemTypes::MAX_ITEMS> &arr)
{
    return std::accumulate(arr.begin(),arr.end(),0) ;
}

void Q1()
{
    std::array<int,ItemTypes::MAX_ITEMS> items{ } ;
    items[ITEM_HEALTH_POTION] = 2 ;
    items[ITEM_TORCH] = 5 ;
    items[ITEM_ARROW] = 10 ;

    printf("The player has %d item(s) in total.\n",countTotalItems(items)) ;
    printf("The player has %d torch(es).\n\n",items[ITEM_TORCH]) ;
}

struct Student
{
    std::string name ;
    int grade ;
};

int getNumberofStudents()
{
    int numStudents{} ;
    while (numStudents <=0)
    {
        std::cout << "How many students would you like to enter?" << std::endl ;
        std::cin >> numStudents ;
    }
    // std::vector<int,numStudents> students ;
    return numStudents ;
}

std::vector<Student> getStudent()
{
    int numStudents{ getNumberofStudents() } ;
    // Create a dynamic vector with numStudents elements.
    std::vector<Student> students(numStudents) ;

    int studentNumber{ 1 } ;

    // Need the anpersand operator modify the values, otherwise will go out
    // of scope and will have the same values as before.
    for (auto &student:students)
    {
        std::cout << "Enter name #" << studentNumber << ": " ;
        std::cin >> student.name ;
        std::cout << "Enter grade #" << studentNumber << ": " ;
        std::cin >> student.grade ;
        ++studentNumber ;
    }

    return students ;
}

bool compareStudents(const Student& A, const Student& B)
{
    return (A.grade > B.grade) ;
}

void Q2()
{
    std::vector<Student> students{ getStudent() } ;
    std::sort( students.begin(), students.end(), compareStudents ) ;

    for (const auto& student : students)
        std::cout << "Student " << student.name << " got a grade of " << student.grade << std::endl ;

}

void mySwap(int &a, int &b)
{
    int temp{ a } ;
    a = b ;
    b = temp ;
}

void Q3()
{
    int a{69} ;
    int b{420} ;
    printf("a = %d & b = %d\n",a,b) ;
    mySwap(a,b) ;
    printf("a = %d & b = %d\n",a,b) ;
}

void printString(const char *str)
{
    while (*str != '\0')
    {
        printf("%c",*str) ;
        ++ str ;
    }
}

void Q4()
{
    printString("Hello World!") ;
}

void Q5a()
{
  int array[]{ 0, 1, 2, 3 };

  for (int count{ 0 }; count < (sizeof(array)/sizeof(array[0])); ++count)
  {
    std::cout << array[count] << ' ';
  }

  std::cout << '\n' ;
}

void Q5b()
{
  int x{ 5 };
  int y{ 7 };

  //const int *ptr{ &x };
  int *ptr{ &x };
  std::cout << *ptr << '\n';
  *ptr = 6;
  std::cout << *ptr << '\n';
  ptr = &y;
  std::cout << *ptr << '\n';
}

void Q5c(int array[], int len)
{
    //for (int element : array)
    for (int *ptr{array} ; ptr < &array[len]; ptr++)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << std::endl ;
}

void Q5()
{
    //Q5a() ;
    //Q5b() ;
    //int array[]{9,7,5,3,1} ;
    //Q5c(array, sizeof(array)/sizeof(array[0])) ;
}

enum class CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,

  MAX_SUITS
};

enum class CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,

  MAX_RANKS
};

struct Card
{
    CardRank leRank{} ;
    CardSuit leSuit{} ;
};

int main()
{
    //Q1() ;
    //Q2() ;
    //Q3() ;
    // Q4() ;
    // Q5() ;

    return 0;
}
