# Table des matières

1. [Introduction](#introduction)
2. [Where i came from and who Im ?](#Where-i-came-from-and-who-Im)
3. [Objectives and progress](#Objectives-and-progress)
4. [My productions](#my-productions)
   1. [TP9](#tp9)
   2. [TP10](#tp10)
   3. [TP12](#tp12)
   4. [TP14](#tp14)
   5. [TP15](#tp15)
5. [Review et aide](#review-et-aide)
6. [Conclusion](#conclusion)
   1. [Points total accumulé](#points-total-accumulé)

# Introduction

Hello ! in this document i will talk about the work i have done this semester in C programming.

I will try to present my work in a really simple matter but in a fairly detailed one where i will go through every Lab and explain what i learned and what i didn't really get right away.

I will try my best to provide the simplest writing possible please grab a coffee and enjoy the reading. ☕️☕☕️

[Recommended Music to read this document](https://www.youtube.com/watch?v=Y7dbQj8XHmM) 🎶

# Where i came from and who Im ?

My name is Khenissi Mehdi i came from the DUT of Reims that specialize in Computer science.

This is my first year in C programming cause in my last studies we exclusively
worked with python and java and even when we got into a C like language like C++
i really didn't understand cause of stress and other factors.

After the first semester where i tried my best to understand even thought i didn't get a super mark cause ima really slow learner but i feel confident that my level really skyrocketed not only in C but also in computer science in general.

# Objectives and progress

One of my first objectives is to really understand everything about memory allocation cause for it was the most confusing thing i ever learned about.
But in the same way i really enjoyed how we can manipulate memory and have total
control on the machine.

Second objective is that this time i will try to understand what im doing and try to ask for help as often as possible to not lose time.

Third objective is to try to do as many as i can of non-graphic Labs that way i can improve my problem solving skills and now my skills to use a pre-coded library.

So as everything is now clear we can start discussing the work.

# My productions:

I will go over every Lab to explain how i did it also what i understood and what i have to review to understand more.I will also provide an auto-evaluation of what i coded you can see the points that i used here [page](http://igm.univ-mlv.fr/~borie/projet_info1.php).

## [TP9](https://github.com/khenissimehdi/C-TP/tree/master/TP9):

This Lab have 3 exercises so i will try to go other everyone of them.
the first exercise consist of only dynamically allocating a space for an array and filling int with integers from 0 to N where the N is chosen by the user.
to use thing i created a function called allocate_integer_array tha takes an integer as size allocate the space using the malloc function and return a pointer to the newly created array of int.
after that i just used a fillArray function that time a pointer to an array and a size and starting filling it from 0 to N.
and of course we have to make the teacher happy that why i freed the array and checked it with valgrind 😎

The second exercise was the hardest by far cause i didn't know how to free a 2d array and also i didn't know how to fill it by letters exactly as described in the exercise.
i basically tried putting code everywhere i had so many if condition and the code was disgusting i will let you take a look at the old code :

```c
void init_tab_2d(char** tab, int n, int m){
       int x,y = 0;
    char  r ;
    char f ;
    r = 'a';
    f = 'a';
    int h = 0;
    for(x = 0; x< n ; x++){
      int c = 0;
          h = 0;
      for(y=0; y <= m ; y++ ){
          if(r+c <= 'z' ){
            tab[x][y] = r + c;
          }
          else{
            tab[x][y] = f + h;
            if(f + h >= 'z'){
              f = 'a';
              h = 0 ;
            }
            h++;
          }
        c++;
      }
      r = r + 1;
    }
}
```

As you noticed the code is really artistic but as we are coding in C WE DON'T CARE ABOUT BEAUTY.
now let's see the new code i mean the cleaner one.

```c
void init_tab_2d(char** tab, int n, int m){
    int x,y = 0;
    for(x = 0; x < n ; x++){

      for(y=0; y < m ; y++ ){
         tab[x][y] = 'a' + ((x+y) % 26);
          }
      }
    }
```

Comparing both of them we can see that the second one is better and also i think that i should've took more time into understanding the advantages of the modulo
Well by putting all this aside we can go take a close look at the interesting part and its the part where i allocate the 2d array.

So i created a a function called allocate_char2D_array that takes two integers one for the first dimension and another for the second one and return a pointer to pointer of type char that represent a 2d char array.

In this function i begin by allocating the first dimension and then looping inside the that dimension and allocating the second one.

The last thing to do is to just go and free the 2d array for this i also created a function that called free_2D_char that takes 2d array of char and integer.
This function will loop through the the tab using the first dimension and free everything then it will free the whole tab.

Now we can attack the last exercise in this Lab this one consists of allocating and copying the arguments to that same array.
Here again nothing magical as we need to allocate space to string we have to first allocate space to the main array then to the words inside that array after that we can just copying them using the function memcpy here is the code for further understanding

```c
char** optizAloc2(int argc, char *argv[]){
    int i ;
    char** new_tab = (char**)malloc(argc * sizeof(char*));
   for( i=0; i< argc ;i++){

   new_tab[i] = (char *)malloc ((length(argv[i]) * sizeof(char))* sizeof (char));
    memcpy(new_tab[i], argv[i], (length(argv[i]) * sizeof(char)));

  }
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

```

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP9    | 10  | 1   | 1    | 1     |        | 1      |           | 2        | 1         | 1          | 2          |         |           |

## [TP10](https://github.com/khenissimehdi/C-TP/tree/master/TP10):

This lab was my favorite Lab so far and when i say this i mean the second part of of it but will as always go through the Lab exercise by exercise.

The first exercise is about coding a swap function but this time its not that simple this time we want the swap function to be able to swap any element regardless of the type means that it doesn't matter of the elements are integers, strings or just chars.
To do this i created a function called swap_mem that take two pointer of type void and a size(more on that later).
you are probably asking why i used void as type well i did this cause we don't want specify if we do that the exercise will make no sense and the code will not working on other type outside of the ones you gave to the function. Alright so with all that out of the way we can go talk about the big chunk of the code or in other way the big idea of the code so if you remember earlier we specified a size so why that ? its just we are going to use that too loop through the strings we declared inside of the function cause that how we are going to to swap any elements regardless of the type is just putting the elements inside a string and swap everything inside pretty cool isn't it ? 🤯

Now we can start my favorite of this Lab the second exercise where we are going to use structures pointer and functions that takes other functions in parameters.

I will start by first explaining what is demanded so basically we have text file that have the name, family name and the age of a person
and we have to code a program that put those persons in a chained list and sort them ether alphabetically or by age.

in this lab we have 3 main important problems the first one is to understand how the Structure work and i mean by that what we have inside of it and what is Cell and \* List.

```c
typedef struct cell
{
    char *first_name; /* String  that contains the first name */
    char *last_name; /* String  that contains the last name */
    int age; /* Integer that contains the age */
    struct cell *next; /*a pointer to the next cell cause here we use chained list*/
} Cell, *List;
```

I think you already noticed but we have something kinda weird here what exactly this mean ?

```c
Cell, *List;
```

well it just the same thing but some times people find using Cell directly kind of confusing
here is how i can explain it using code :

```c
typedef struct {
  ...
}Cell, *List;

Cell *lst = List lst;
```

Now lets go to the second most important part and its how we going to read the text file and use the inputs ?
Thanks to fopen that can read a file giving it a certain fileName and fscan that can parse that path line by line we can do a code that looks like this

```c
List head = NULL;
  char first[50];
  char last[50];
  int age;

  FILE *ptr = fopen("fileName.txt", "r");/*opening the file */
  if (ptr == NULL)
  {
    printf("no such file.");
    return 0;
  }
  while (fscanf(ptr, "%s %s %d", first, last, &age) == 3)
  /* parse every line and putting everything we get into 3 variables first, last and age*/
  {
    ...
  }

  fclose(ptr);/*REALLY IMPORTANT ALWAYS CLOSE THE FILE OPNER OR YOU WILL GET MEMORY LOSE*/
```

Now we go check the hardest part of this Lab and tis the function ordered_insertion
this function takes the head of the list a new cell mean and a function.

```c
List *l ;/* head of the chained list */
Cell *new ;/* the new cell that we gonna add */
int order_func(Cell *, Cell *); /* the function that contains the comparing logic */
```

After this out of the way now we have to start coding the function we have 3 things to consider while coding this function the first one is by making sure that the head is not empty

```c
 if (*l == NULL)
  {
    *l = new;
    return;
  }
```

Then we have to check if the head of the list is in the right place comparing it with the new cell using the order function

```c
 else if (order_func(*l, new))
  {
    new->next = *l;
    *l = new;
    return;
  }
```

in the end we have the normal case where we going to loop while using the order function and put the the cell in the right place.

```c
else
  {
    ptr = *l;
    while (ptr->next != NULL && !order_func(ptr->next, new))
      ptr = ptr->next;

    new->next = ptr->next,
    ptr->next = new;
  }
```

and this pretty much it for this Lab the difficulty.

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP10   | 11  | 1   | 1    | 1     |        | 1      | 1         |          | 2         | 1          | 1          | 1       |           |             |        |

## [TP12](https://github.com/khenissimehdi/C-TP/tree/master/TP12)

This lab is pretty much the same as the Lab 10 except this time we have to perform a search of a certain word inside a chained list aht we created and we have to create two version of code a naif one and smart one so lets start by the naif one.
Here we are going to look just at the search function :

```c
int check_exist(List *lst, char *word)
{
  List current = (*lst);

  while (current != NULL)
  {

    if (strcmp(current->word, word) == 0)
    {
      return 1;
    }

    current = current->next;
  }
  return 0;
}
```

As we can see here we we loop through all the node using a while loop this is simple but its not the best way to do it when we have a big number of words leaving us with a complexity of O(n) that is basically so bad for us.

That why the second version better cause we use hash table that and for this we are going to need a hash function.
a hash table is just a structure that can map keys to values and all this is done thanks to hash function that will transform the value into a key.
or even in simpler wat a hash table is simply an array that is addressed via a hash function.
Here is a gif that explains the process

![Alt Text](https://d18l82el6cdm1i.cloudfront.net/uploads/34EvJ7agjl-hash_table.gif)

With all this said we can now look at th code first lets see the hash function.

```c
unsigned hash(char *elt)
{
  int i;
  unsigned h;

  h = 0;

  for (i = 0; elt[i] != '\0'; i++)
  {
    h += ((i + 1) * elt[i]);
  }

  return h % 4096;
}
```

As we can see here we are just adding ((i + 1) \* elt[i]); to h and doing a modulo by 4096 to stay on the range nth really magical just an application of what demanded.
now lets see the check_exist function :

```c
int check_existTAB(Node *tab[], unsigned hashcode)
{

  if (tab[hashcode] != NULL)
  {
    return 1;
  }

  return 0;
}
```

_Voila !_ comparing it with the naif one our new function is simpler and also faster and that exactly what we want we passed form O(n) to O(1).
this is for this Lab it was really good working it and comparing the naif to the smart one and to see how a really simple solution is sometimes the best.

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP4    | 11  | 2   | 1    | 1     |        | 1      |           | 1        | 1         | 2          | 1          | 1       |           |             |        |

## [TP5](https://github.com/Kwaaac/ProgC/tree/main/TP5)

Le TP5 à été vraiment excellent pour moi. J’avais des problèmes avec les tableaux parce que j’avais l’impression de ne pas comprendre comment ils fonctionnaient en termes d’initialisation et en passage par adresse.

Ce TP a le grand avantage de tout revoir et de tout utiliser sur les tableaux, et fait un très bon exercice et m’a permis de grandement progresser sur ce plan là.

Sur ce TP, j’ai pu avoir une bonne avancée en termes de completion de code.
En effet, j’avais d’abord fait une première version du TP qui fonctionnait mais une version de base, elle était classique selon moi, à part une fonction que j’ai fait afin de factoriser pas mal de code:

```c
/**
 * Push the second array into the first
 *
 * @param first First array
 * @param second Second array
 * @param first_index Starting index to fill the first array
 * @param second_index Starting index to push from the second array
 * @param size_second Size of the second array
 */
void push_array(int *first, int *second, int first_index, int second_index, int size_second) {
    int i;
    for (i = second_index; i < size_second; i++, first_index++) {
        first[first_index] = second[i];
    }

    first[first_index] = -1;
}
```

Cette fonction va, comme l’indique le commentaire, push tout un tableau dans un autre, avec une gestion des index.
Cette fonction est extrêmement utile et est souvent utilisé pour remplacer des boucle for intempestives

Dans cette version, je n’avais pas gérer les erreurs, ni des test et le makefile n’était pas clair.

Puis Guillaume DOMART à fait la revue [#3](https://github.com/Kwaaac/ProgC/issues/3#issue-772243545) dans laquelle il a exposé plusieurs point d’améliorations que j’ai corrigé en grande quantité !
Dans l’issue Git, vous pourrez retrouver le commit [5c33148](https://github.com/Kwaaac/ProgC/commit/5c33148b50388ad7f924be6c0eed7fba6e1935c4) qui contient une description de mes modifications suite à la review et toutes mes modifications qui vont avec.
En résumé j’ai pousser les tests de mes fonctions dans le main, et j’ai véritablement gérer les erreurs dans la fonction fill array pour empêcher l’ajout de nombres négatifs ce qui rend son utilisation _normalement_ impossible à rater.

Et en prime j’ai pu mettre à profit la création de Makefile.

En somme, ce TP m’a permis de grandement progresser sur l’utilisation des tableaux, la gestion des erreurs, la factorisation de code, une gestion des tests avec des arguments données et sur l’utilisation des Makefiles.

Si il y a une chose dont je suis sûr à ce stade c’est que je pense avoir maîtrisé le principe des fonctions, des types et des variables en C.

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP5    | 7   | 1   | 1    | 1     |        |        | 1         | 1        | 1         | 1          |

## [TP15](https://github.com/khenissimehdi/C-TP/tree/master/TP15)

This Lab was the hardest so far in term of understanding how some libraries works.
In This lab we will have to code a Reverse Polish calculator here is quick demo of what we expect to have.

![Alt Text](https://floatingoctothorpe.uk/2018/rpn-evaluation-animation.gif)

first thing i did is to implment the stack so went and created a stack.h and a stack.c unitl here everything is kinda simple.
after that i created two files operation.c and operation.h where i put my operations like addition, division etc and after putting all this aside now we got tot the hard part.

the hard part is that you have to know what to use when i started this Lab i was going ot a direction where i was going to create my own parser sadly my ignornce have hidden from me that this parser already exisit and its caled strtol and its really esay to use.

```c
  char *endptr;
  long val;
    if (isNumeric(word) == 1)
      {
        val = strtol(word, &endptr, 10);
        push_stack(s, val);
      }
      else
      {
        printf("Unknown operation %s \n", word);
      }
```

And yes just lik this 80 % of the work is already done so please let me explain what is going on here.
in the if we check if the input is a number using the isdigit function from ctype.h by looping thoogh all the input and if it not the case we say that the operation is unknown.

```c
int isNumeric(char *str)
{
  int i;
  for (i = 0; i < strlen(str); i++)
  {
    if (isdigit(str[i]) == 1)
    {
      return 1;
    }
  }

  return 0;
}
```

a

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP6    | 10  | 1   | 1    | 1     | 1      | 1      | 2         | 1        | 1         |            |            |         |           | 1           |

# Review et aide

# Conclusion

## Points total accumulé:

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| Total  | 80  | 9   | 11   | 9     | 8      | 10     | 7         | 7        | 3         | 3          | 3          | 3       | 0         | 0           | 4      |

Les points accumulés dépassent largement les objectifs de base établis en 2018 donc je suis véritablement très fier de ça ! Bon ça démontre plus que je me suis arraché à faire les TP, après est-ce qu’ils sont correctement réalisés, c’est une autre affaire.

Merci d’avoir lu ce rapport sur mon activité du semestre 1 ! Je vous souhaite un bon courage après avoir lu ces pavés !
