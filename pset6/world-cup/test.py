dict = {'a': 10}





def dict_to_list(dict):
    temp = []
    try:
        key = list(dict.keys())
        value = list(dict.values())
        item = [key[0], value[0]]
        return item
    except:
        return dict
    return temp

res = dict_to_list(dict)
print(res)


# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000
counts = []

def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            dict_teams = []
            dict_counts = []
            name = row['team']
            rating = int(row['rating'])
            dict_teams = [name,rating]
            dict_counts =[name, 0]
            teams.append(dict_teams)
            counts.append(dict_counts)

    # TODO: Simulate N tournaments and keep track of win counts
    for j in range(N):
        simulate_tournament(teams)


    # Print each team's chances of winning, according to simulation
    for j in counts:
        print(f"{j[0]}: {j[1] * 100 / N:.1f}% chance of winning")



def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""


    rating1 = team1[1]
    rating2 = team2[1]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []
    teams = dict_to_list(teams)
    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners

def dict_to_list(dict):
    temp = []
    for n in dict:
        try:
            key = list(n.keys())
            value = list(int(n.values()))
            item = [key[0], value[0]]
            temp.append(item)
        except:
            return dict
    return temp

def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    teams = dict_to_list(teams)
    if len(teams) == 2:
        try:
            win = []
            win.append(simulate_round(teams))
            winner = str(win[0][0][0])
            for i in counts:
                if i[0] == winner:
                    i[1] = i[1] + 1
            return
        except:
            win = []
            win.append(simulate_round(teams))
            winner = list(win[0][0].keys())
            winner = str(win[0])
            for i in counts:
                if i[0] == winner:
                    i[1] = i[1] + 1



    else:
        teams = simulate_round(teams)
        simulate_tournament(teams)


if __name__ == "__main__":
    main()
