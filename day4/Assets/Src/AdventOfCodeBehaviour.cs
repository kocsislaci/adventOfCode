using System.Collections.Generic;
using System.Collections.ObjectModel;
using UnityEngine;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

internal struct Game {
    public readonly Collection<int> Winning;
    public readonly Collection<int> Guessed;
    public Game(Collection<int> winning = null, Collection<int> guessed = null) {
        Winning = winning ?? new();
        Guessed = guessed ?? new();
    }
}

public class AdventOfCodeBehaviour : MonoBehaviour
{
    void Awake() {
        var result = 0;
        List<int> timesList = new(0){
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        };
        
        foreach (var line in File.ReadLines(Application.dataPath + "/Resources/Input/input.txt")) {
            Game game = new Game(null, null);
            var splitLines = line.Split('|');
            var winningMatches = Regex.Matches(splitLines[0], @"\d+");
            foreach (Match match in winningMatches) {
                if (int.TryParse(match.Value, out int number)) {
                    game.Winning.Add(number);
                }
            }

            game.Winning.RemoveAt(0);
            var guessedMatches = Regex.Matches(splitLines[1], @"\d+");
            foreach (Match match in guessedMatches) {
                if (int.TryParse(match.Value, out int number)) {
                    game.Guessed.Add(number);
                }
            }

            var calced = game.Guessed.Count(guess => game.Winning.Any(win => guess == win));
            
            var times = timesList[0]; // this will not change
            timesList.RemoveAt(0); // shift the accumulator list
            timesList.Add(1);

            // calc the new accumulator list
            for (int j = 0; j < times; j++){ // fill with the past value times
                for (int i = 0; i < calced; i++) { // fill the accumulator
                    timesList[i] += 1;
                }
            }

            // add the corresponding element to the accum
            result += times;
        }
        
        print(result);
    }
}
