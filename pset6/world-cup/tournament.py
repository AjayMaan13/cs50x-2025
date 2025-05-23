import csv
import sys
import random

# Number of simluations to run
N = 1000


# My mistakes when I first created this file was
# 1. That I didn't understood how list teams will store data, I thought that it will take in values like [{"rome":1100}]
#   But instead it stored values like [{'team':'rome','rating':1100}]


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    filename = sys.argv[1]
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            team = row
            team["rating"] = int(team["rating"])
            teams.append(team)
    print(teams)
    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for simulation in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1
    print(counts)
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    rounds = len(teams)
    if rounds >= 2:
        teams = simulate_round(teams)
        return simulate_tournament(teams)
    else:
        winner = teams[0]["team"]
        return winner


if __name__ == "__main__":
    main()