#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h> //round(value)

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    // input text from user
    string text = get_string("Text: ");

    // return number of letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // calculte L : average number of letters per 100 words
    float L = (letters / (float) words) * 100;

    // calculate S : average number of sentences per 100 words
    float S = (sentences / (float) words) * 100;

    //Calcuate Coleman-Liau index
    float cal_index =  0.0588 * L - 0.296 * S  - 15.8;
    int index = (int) round(cal_index);


    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


// functions
int count_letters(string text)
{
    //local variables
    int count = 0;

    // 65 = A and 90 = Z
    // loop through sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int val_letter = toupper(text[i]);

        if (val_letter >= 65 && val_letter <= 90)
        {
            count += 1;
        }

    }
    return count;
}


int count_words(string text)
{
    //local variables
    int count = 0;
    int aux_words;

    // 32 = " " 45= -
    // loop through sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int val_word = toupper(text[i]);

        if (val_word  == 32)
        {
            if (val_word == 32)
            {
                do
                {
                    i++;
                    aux_words = toupper(text[i]);
                }
                while (aux_words == 32);
            }
            else if (val_word == 45)
            {
                do
                {
                    i++;
                    aux_words = toupper(text[i]);
                }
                while (aux_words != 45);
            }
            count += 1;
        }

    }
    return count + 1;
}

int count_sentences(string text)
{
    //local variables
    int count = 0;

    // loop through sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int val_sentence = text[i];

        // 46 = . 33 = ! 63 = ?
        if (val_sentence == 46 || val_sentence == 33 || val_sentence == 63)
        {
            if (val_sentence == 46)
            {
                do
                {
                    i++;
                    val_sentence = toupper(text[i]);
                }
                while (val_sentence == 46);
            }
            count += 1;
        }
    }
    return count;
}