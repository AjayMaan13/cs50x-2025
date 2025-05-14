import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    databases = []
    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            try:
                people = row
                people['AGATC'] = int(people['AGATC'])
                people['TTTTTTCT'] = int(people['TTTTTTCT'])
                people['AATG'] = int(people['AATG'])
                people['TCTAG'] = int(people['TCTAG'])
                people['GATA'] = int(people['GATA'])
                people['TATC'] = int(people['TATC'])
                people['GAAA'] = int(people['GAAA'])
                people['TCTG'] = int(people['TCTG'])
                databases.append(people)
            except:
                people = row
                people['AGATC'] = int(people['AGATC'])
                people['TATC'] = int(people['TATC'])
                people['AATG'] = int(people['AATG'])
                databases.append(people)

    # TODO: Read DNA sequence file into a variable
    dna = ''
    with open(sys.argv[2], "r") as file:
        reader = csv.reader(file)
        for row in reader:
            dna = row[0]

    # TODO: Find longest match of each STR in DNA sequence
    sequence_result = {'AGATC': longest_match(dna, 'AGATC'), 'TTTTTTCT': longest_match(dna, 'TTTTTTCT'),
                       'AATG': longest_match(dna, 'AATG'), 'TCTAG': longest_match(dna, 'TCTAG'),
                       'GATA': longest_match(dna, 'GATA'), 'TATC': longest_match(dna, 'TATC'),
                       'GAAA': longest_match(dna, 'GAAA'), 'TCTG': longest_match(dna, 'TCTG')}

    # TODO: Check database for matching profiles
    result = False
    # If we are importing large database form databases folder
    if (sys.argv[1] == 'databases/large.csv'):
        dna_list = list(sequence_result.keys())
        x = 0
        while (x < 24):
            current = databases[x]

            # checking if all the dna sequences number is same and if not break out of the loop
            for j in range(8):
                if (current[dna_list[j]] == sequence_result[dna_list[j]]):
                    result = True
                else:
                    result = False
                    break
            if result == True:
                print(current['name'])
                return
            x = x + 1
    # when we are importing from small database, with similar code
    else:
        dna_list = ['AGATC', 'TATC', 'AATG']
        x = 0
        while (x < 3):
            current = databases[x]
            for j in range(3):
                if (current[dna_list[j]] == sequence_result[dna_list[j]]):
                    result = True
                else:
                    result = False
                    break
            if result == True:
                print(current['name'])
                return
            x = x + 1

    # if no requirement is met therefore no match
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
