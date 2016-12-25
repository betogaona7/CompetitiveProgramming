
word = raw_input("")
 
def check(word, idx):
    for i in range(idx, len(word)):
        if (word[i].islower()):
            return 0
    return 1
 
if check(word, 0):
    new_word = word.lower()
elif check(word, 1):
    new_word = word[0].upper() + word[1:].lower()
else:
    new_word = word
 
print new_word
