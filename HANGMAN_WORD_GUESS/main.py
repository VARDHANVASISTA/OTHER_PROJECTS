import random
import logo_of_game
import hangman_stages
import words_list

print("!!WELCOME TO..")
print(logo_of_game.logo)
ch = random.choice(words_list.word_list)
print(ch)
nch = len(ch)
lives = 6 
tl = 6
sl = []
for i in range(nch):
    sl.append('_')
print(f"You need to guess a {nch} letter word...")
print(f"!!!You have 6 chances to SAVE a MAN from getting HANGED!!!")
print(logo_of_game.hearts[0])
print("!Each time you guess a wrong letter, the man LOOSES A LIFE!")
print(sl)
eog = False
while not eog:
    gl = input("Guess a letter >> ").lower()
    pos = -1
    if gl in sl:
        print(f"You have already guessed the letter >> '{gl}'...Try other letter...")
    else:
        for i in ch:
            pos += 1
            if i == gl:
                sl[pos] = i
        if gl not in ch:
            lives -= 1
            print(f"'{gl}' is NOT PRESENT in the word...")
            print(hangman_stages.stages[tl - lives])
            print(logo_of_game.hearts[tl - lives])
            print(f"LIVES LEFT = {lives}")
            if lives == 0:
                print("Sorry...\nAll LIVES lost!!")
                print(F"The WORD was >> {ch.upper()}")
                print("!!YOU LOOSE!!")
                eog = True
        print(sl)
        if '_' not in sl:
            eog = True
            print("Congratulations....\n!!YOU WIN!!")
            print(logo_of_game.win)
