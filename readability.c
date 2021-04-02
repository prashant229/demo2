#include <stdio.h>
#include <math.h>
float count_letters(char text[]);
float count_sentences(char text[]);

int main()
{
    char texti[1000];
    //taking the text input
    printf("text :");
    scanf("\n%[^\n]s", texti);
    //finding number of letters and sentences per 100 words
    float L = (float)count_letters(texti);
    float S = (float)count_sentences(texti);
    //finding the index
    float Index = (0.0588 * L) - (0.296 * S) - 15.8;
    float Grade =round(Index);
    if(Grade>16)
    printf("\nGrade :16+");
    else
    printf("\nGrade :%f",Grade);
    return 0;
}
//function declarations!
float count_letters(char text[])
{
    //word is initialised with 1 as last word in not counted
    int i = 0, word = 1;
    float count1 = 0;
    while (text[i] != 0)
    {
            //countings the letters
        if ('A' <= text[i] && 'Z' >= text[i])
            count1++;
        else if ('a' <= text[i] && 'z' >= text[i])
            count1++;
            //counting the words
        else if (' ' == text[i])
            word++;
        i++;
    }
     count1=(count1*100)/word;
    return count1;
}
float count_sentences(char text[])
{
    int i = 0, word = 1;
    float count = 0;
    while (text[i] != 0)
    {  //counting the sentences
        if ('.' == text[i] || '!' == text[i] || '?' == text[i])
            count++;
            //counting
        else if (' ' == text[i] )
            word++;
        i++;
    }

    count=(count*100)/word;
    return count;
}