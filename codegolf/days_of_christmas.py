_1="First Second Third Fourth Fifth Sixth Seventh Eighth Ninth Tenth Eleventh Twelfth".split(' ')
_2="A Partridge in a Pear Tree.,Two Turtle Doves,Three French Hens,Four Calling Birds,Five Gold Rings,Six Geese-a-Laying,Seven Swans-a-Swimming,Eight Maids-a-Milking,Nine Ladies Dancing,Ten Lords-a-Leaping,Eleven Pipers Piping,Twelve Drummers Drumming".split(',')
for i in range(12):
    print(f"On the {_1[i]} day of Christmas\nMy true love sent to me")
    j = i
    while(j>=0):
        if(j==0):
            print(_2[j])
        elif(j==1):
            print(f"{_2[j]}, and\n{_2[j-1]}")
            j-=1
        else:
            print(f"{_2[j]},")
        j-=1
    print()
