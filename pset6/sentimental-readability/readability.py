# TODO
import math


def main():

    # Taking input
    text = input("Text: ")
    L = count_letters(text)
    W = count_words(text)
    S = count_sentences(text)

    # Main line of the code where all the calculatio is done
    index = int(round(0.0588 * (L * 100.0 / W) - 0.296 * (S * 100.0 / W) - 15.8))

    # Printing the result of the code
    if (index >= 16):
        print("Grade 16+")
        return
    if (index < 1):
        print("Before Grade 1")
        return
    else:
        print(f"Grade {index}")


# Counting the number of letters by checking uppercase and lowercase letters
def count_letters(word):
    length = len(word)
    real_letters = 0
    for i in range(length):
        if (word[i].islower() == True or word[i].isupper() == True):
            real_letters = real_letters + 1
    return real_letters


# Counting the number of words by finding the number of spaces in the text
def count_words(word):
    words = 1
    for i in range(len(word)):
        if (word[i] == " "):
            words = words + 1

    return words


# Counting the number of sentences by counting the number of ending characters of an line
def count_sentences(word):
    sentences = 0
    for k in range(len(word)):
        if (word[k] == "." or word[k] == "!" or word[k] == "?"):
            sentences = sentences + 1
    return sentences


if __name__ == "__main__":
    main()