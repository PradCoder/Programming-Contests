import Html
import Html.Attributes

imageUrl1 = "https://img.favpng.com/19/21/23/math-word-problems-mathematics-problem-solving-png-favpng-54qGjN1e1sEfDDS98SLh904Ph.jpg"
imageWidth = 1280
imageHeight = 1200
imageScale = 0.3
imageMove = (-30,15)
pic = move imageMove <| scale imageScale <| html imageWidth imageHeight <| Html.img [Html.Attributes.src imageUrl1][]
imageUrl2= "https://i.ytimg.com/vi/1cDbjMg2UNA/maxresdefault.jpg"
imageUrl3= "https://image.slidesharecdn.com/nonlinear-1207170428110019-8/95/animal-kingdom-10-728.jpg?cb=1207145388"

myShapes model =
case model.state of
Start ->
[
pic |>move(-90,-60) |>scale 0.4,
title |>move (-70,50),
transition Lev3 T1,
text "Level 3"
|> centered
|> filled black
|> scale 0.5
|> move (60.5,18.5)
|> notifyTap T1,
transition Lev2 T3,
text "Level 2"
|> filled black
|> scale 0.5
|> move (-9,18.5)
|> notifyTap T3,
transition Lev1 T5,
text "Level 1"
|> filled black
|> scale 0.5
|>move (-69,18.5)
|> notifyTap T5,


transition Lev4 T19,
text "Level 4"
|> filled black
|> scale 0.5
|>move (-39,-1.5)
|> notifyTap T19,
transition Lev5 T20,
text "Level 5"
|> filled black
|> scale 0.5
|>move (21,-1.5)
|> notifyTap T20
]
-- Designing each level for the word problems
Level1 ->
[ backGround,
hints1 |>move (65,32)
, answerBox1 |>move (-50,-31)
, highlight
|> move (-30,38)
, highlight
|> move (-38,38)
, highlight
|> move (-31,33)
, highlight
|> move (-50,28)
, highlight
|> move (-63,28)
, question1
|> scale 0.8
|> move (-30,12)
, if (model.graph1) then
graph1 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes1) then

group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. There is an adult who brought 2 children"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (30, 11)
else
text ""
|> filled black

,transition Home T6, -- Able to move to the home page from a level
transition Next T9 -- Able to move to the next level
]
Level2 ->
[ backGround,
hints2 |>move (65,32)
, answerBox2 |>move (-50,-31)
, highlight
|> move (-11.5,37.5)
|> scaleX 1.3
, highlight
|> move (-67,32)
, highlight
|> move (-45,27)
|> scaleX 1.2
, highlight
|> move (-96,22)
|> scaleX 0.8
, question2
|> scale 0.8
|> move (-29,10)
, if (model.graph2) then
graph2 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes2) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text " so you can isolate for 2 variables!"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (36, 11)
else
text ""
|> filled black
,
transition Home T4,
transition Back T8,
transition Next T10


]


Level3 ->
[ backGround,
hints3 |>move (65,32)
, answerBox3 |>move (-50,-31)
, highlight
|> move (-42.5,37)
, highlight
|> move (-51,22)
|> scaleX 0.85
, question3
|> scale 0.8
|> move (-29,10)
, if (model.graph3) then
graph3 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes3) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. Start with R + G = 100"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (36, 11)
else
text ""
|> filled black

, transition Home T2
, transition Back T7
, transition Next T10A

]
Level4 ->
[ backGround,
hints4 |>move (65,32)
, answerBox4 |>move (-50,-31)
, highlight
|> move (-28,37)
, highlight
|> move (-7,32)
, highlight
|> move (-24,32)
, highlight
|> move (-67,22)
|> scaleX 0.85
, question4
|> scale 0.8
|> move (-29,10)
, if (model.graph4) then
graph4 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes4) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. Start with y = 8x"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (36, 11)
else
text ""
|> filled black

, transition Home T4A
, transition Back T7A
, transition Next T10B

]
Level5 ->
[ backGround,
hints5 |>move (65,32)
, answerBox5 |>move (-50,-31)
, highlight
|> move (-13,32)
, highlight
|> move (-6,22)
|> scaleX 0.85
, question5
|> scale 0.8
|> move (-29,10)
, if (model.graph5) then
graph5 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes5) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. Average speed=total_distance/total_time"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (30, 11)
else
text ""
|> filled black

, transition Home T4B
, transition Back T7B

]
-- Assigning different messages when you get an answer wrong/right
RightAns1 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11A,
transition NextQ T16
]

RightAns2 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11B,
transition NextQ T17
]
RightAns3 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11C,
transition NextQ T17A
]
RightAns4 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11D,
transition NextQ T17B
]
RightAns5 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11E
]
WrongAns1 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12A
, transition OK T13

]
WrongAns2 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12B
, transition OK T14

]
WrongAns3 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12C
, transition OK T15

]
WrongAns4 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12D
, transition OK T15A

]
WrongAns5 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12E
, transition OK T15B

]
-- using html to import pictures for backgrounds
background1 = group [ square 300
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl] [])
|> scale 0.15
|> move (-95,60)
]
background2 = group [ square 300
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.15
|> move (-95,60)
]
type Msg = Tick Float GetKeyState
| T1
| T2
| T3
| T4
| T4A
| T4B
| T5
| T6
| T7
| T7A
| T7B
| T8
| T9
| T10
| T10A
| T10B
| T11A
| T11B
| T11C
| T11D
| T11E
| T12A
| T12B
| T12C
| T12D
| T12E
| T13
| T14
| T15
| T15A
| T15B
| T16
| T17
| T17A
| T17B
| T19
| T20
| Graph1
| Graph2
| Graph3
| Graph4
| Graph5
| CommonMistakes1
| CommonMistakes2
| CommonMistakes3
| CommonMistakes4
| CommonMistakes5
| Correct1
| Correct2
| Correct3
| Correct4
| Correct5
| Incorrect1
| Incorrect2
| Incorrect3
| Incorrect4
| Incorrect5
| Right1
| Right2
| Right3
| Right4
| Right5
| Wrong1
| Wrong2
| Wrong3
| Wrong4
| Wrong5

type State = Start
| Level5
| Level4
| Level3
| Level2
| Level1
| RightAns1
| RightAns2
| RightAns3
| RightAns4
| RightAns5
| WrongAns1
| WrongAns2
| WrongAns3
| WrongAns4
| WrongAns5



update msg model = case msg of
Tick t _ -> { model | time = t }

Graph1 -> if model.graph1 ==True then
{model | graph1 =False}
else
{model |graph1 =True}
Graph2 -> if model.graph2 ==True then
{model | graph2 =False}
else
{model |graph2 =True}
Graph3 -> if model.graph3 ==True then
{model | graph3 =False}
else
{model |graph3 =True}
Graph4 -> if model.graph4 ==True then
{model | graph4 =False}
else
{model |graph4 =True}
Graph5 -> if model.graph5 ==True then
{model | graph5 =False}
else
{model |graph5 =True}
CommonMistakes1 -> if model.commonMistakes1 ==True then
{model | commonMistakes1 =False}
else
{model |commonMistakes1 =True}

CommonMistakes2 -> if model.commonMistakes2 ==True then
{model | commonMistakes2 =False}
else
{model |commonMistakes2 =True}

CommonMistakes3 -> if model.commonMistakes3 ==True then
{model | commonMistakes3 =False}
else
{model |commonMistakes3 =True}
CommonMistakes4 -> if model.commonMistakes4 ==True then
{model | commonMistakes4 =False}
else
{model |commonMistakes4 =True}

CommonMistakes5 -> if model.commonMistakes5 ==True then
{model | commonMistakes5 =False}
else
{model |commonMistakes5 =True}
Correct1 -> if model.correct1 ==False && model.incorrect1 == False then
{model | correct1 =True}
else
{model |correct1 =False}

Correct2 -> if model.correct2 ==False && model.incorrect2 == False then
{model | correct2 =True}
else
{model |correct2 =False}

Correct3 -> if model.correct3 ==False && model.incorrect3 == False then
{model | correct3 =True}
else
{model |correct3 =False}
Correct4 -> if model.correct4 ==False && model.incorrect4 == False then
{model | correct4 =True}
else
{model |correct4 =False}

Correct5 -> if model.correct5 ==False && model.incorrect5 == False then
{model | correct5 =True}
else
{model |correct5 =False}
Incorrect1 -> if model.incorrect1 ==False && model.correct1 == False then
{model | incorrect1 =True}
else
{model |incorrect1 =False}
Incorrect2 -> if model.incorrect2 ==False && model.correct2 == False then
{model | incorrect2 =True}
else
{model |incorrect2 =False}
Incorrect3 -> if model.incorrect3 ==False && model.correct3 == False then
{model | incorrect3 =True}
else
{model |incorrect3 =False}
Incorrect4 -> if model.incorrect4 ==False && model.correct4 == False then
{model | incorrect4 =True}
else
{model |incorrect4 =False}
Incorrect5 -> if model.incorrect5 ==False && model.correct5 == False then
{model | incorrect5 =True}
else
{model |incorrect5 =False}
T1 ->
case model.state of
Start ->
{ model | state = Level3 }
otherwise ->
model
T2 ->
case model.state of
Level3 ->
{ model | state = Start }
otherwise ->
model
T3 ->
case model.state of
Start ->
{ model | state = Level2 }
otherwise ->
model
T4 ->
case model.state of
Level2 ->
{ model | state = Start }
otherwise ->
model
T4A ->
case model.state of
Level4 ->
{ model | state = Start }
otherwise ->
model
T4B ->
case model.state of
Level5 ->
{ model | state = Start }
otherwise ->
model
T5 ->
case model.state of
Start ->
{ model | state = Level1 }
otherwise ->
model
T6 ->
case model.state of
Level1 ->
{ model | state = Start }
otherwise ->
model

T7 ->
case model.state of
Level3 ->
{ model | state = Level2 }
otherwise ->
model

T7A ->
case model.state of
Level4 ->
{ model | state = Level3 }
otherwise ->
model

T7B ->
case model.state of
Level5 ->
{ model | state = Level4 }
otherwise ->
model
T8 ->
case model.state of
Level2 ->
{ model | state = Level1 }
otherwise ->
model
T9 ->
case model.state of
Level1 ->
{ model | state = Level2 }
otherwise ->
model
T10 ->
case model.state of
Level2 ->
{ model | state = Level3 }
otherwise ->
model
T10A ->
case model.state of
Level3 ->
{ model | state = Level4 }
otherwise ->
model
T10B ->
case model.state of
Level4 ->
{ model | state = Level5 }
otherwise ->
model
T11A ->
case model.state of
RightAns1 ->
{ model | state = Start }
otherwise ->
model
T11B ->
case model.state of
RightAns2 ->
{ model | state = Start }
otherwise ->
model
T11C ->
case model.state of
RightAns3 ->
{ model | state = Start }
otherwise ->
model
T11D ->
case model.state of
RightAns4 ->
{ model | state = Start }
otherwise ->
model
T11E ->
case model.state of
RightAns5 ->
{ model | state = Start }
otherwise ->
model
T12A ->
case model.state of
WrongAns1 ->
{ model | state = Start }
otherwise ->
model
T12B ->
case model.state of
WrongAns2 ->
{ model | state = Start }
otherwise ->
model
T12C ->
case model.state of
WrongAns3 ->
{ model | state = Start }
otherwise ->
model
T12D ->
case model.state of
WrongAns4 ->
{ model | state = Start }
otherwise ->
model
T12E ->
case model.state of
WrongAns5 ->
{ model | state = Start }
otherwise ->
model
T13 ->
case model.state of
WrongAns1 ->
{ model | state = Level1 }
otherwise ->
model
T14 ->
case model.state of
WrongAns2 ->
{ model | state = Level2 }
otherwise ->
model
T15 ->
case model.state of
WrongAns3 ->
{ model | state = Level3 }
otherwise ->
model
T15A ->
case model.state of
WrongAns4 ->
{ model | state = Level4 }
otherwise ->
model

T15B ->
case model.state of
WrongAns5 ->
{ model | state = Level5 }
otherwise ->
model
T16 ->
case model.state of
RightAns1 ->
{ model | state = Level2 }
otherwise ->
model
T17 ->
case model.state of
RightAns2 ->
{ model | state = Level3 }
otherwise ->
model
T17A ->
case model.state of
RightAns3 ->
{ model | state = Level4 }
otherwise ->
model
T17B ->
case model.state of
RightAns4 ->
{ model | state = Level5 }
otherwise ->
model
T19 ->
case model.state of
Start ->
{ model | state = Level4 }
otherwise ->
model
T20 ->
case model.state of
Start ->
{ model | state = Level5 }
otherwise ->
model

Right1 ->
case model.state of
Level1 ->
{ model | state = RightAns1 }
otherwise ->
model

Right2 ->
case model.state of
Level2 ->
{ model | state = RightAns2 }
otherwise ->
model
Right3 ->
case model.state of
Level3 ->
{ model | state = RightAns3 }
otherwise ->
model
Right4 ->
case model.state of
Level4 ->
{ model | state = RightAns4 }
otherwise ->
model
Right5 ->
case model.state of
Level5 ->
{ model | state = RightAns5 }
otherwise ->
model
Wrong1 ->
case model.state of
Level1 ->
{ model | state = WrongAns1 }
otherwise ->
model

Wrong2 ->
case model.state of
Level2 ->
{ model | state = WrongAns2 }
otherwise ->
model
Wrong3 ->
case model.state of
Level3 ->
{ model | state = WrongAns3 }
otherwise ->
model
Wrong4 ->
case model.state of
Level4 ->
{ model | state = WrongAns4 }
otherwise ->
model
Wrong5 ->
case model.state of
Level5 ->
{ model | state = WrongAns5 }
otherwise ->
model
background = group [
rect 200 300
|> filled (rgb 64 224 208)
]

-- Different button positions
type ButtonPosition = Lev1 | Lev2 | Lev3 | Lev4 | Lev5 | Home | Back | Next | OK | NextQ

transition : ButtonPosition -> Msg -> Shape Msg
transition pos msg = case pos of
Lev1 -> group [roundedRect 30 15 2
|> filled orange
] |> move (-60,20)
|> notifyTap msg

Lev2 -> group [roundedRect 30 15 2
|> filled orange
] |> move (0,20)
|> notifyTap msg
Lev3 -> group [roundedRect 30 15 2
|> filled orange
] |> move (60,20 )
|> notifyTap msg
Lev4 -> group [roundedRect 30 15 2
|> filled orange
] |> move (-30,0.5 )
|> notifyTap msg

Lev5 -> group [roundedRect 30 15 2
|> filled orange
] |> move (30,0.5 )
|> notifyTap msg

-- using html attributes to get certain symbols for the program
Home -> group [ html 10 16
( Html.img [Html.Attributes.width 10
, Html.Attributes.src "https://static.thenounproject.com/png/901844-200.png"][]
)
] |> move (-87,59.5) |> notifyTap msg
Back -> group [ html 10 16
( Html.img [Html.Attributes.width 10
, Html.Attributes.src "https://images.vexels.com/media/users/3/128927/isolated/preview/25652eb37d257753ffab9b4ac8edfa28-travel-airport-round-icon-arrow-by-vexels.png"][]
)
] |> rotate (degrees 180) |> move (70,-59.5) |> notifyTap msg
Next -> group [ html 10 16
( Html.img [Html.Attributes.width 10
, Html.Attributes.src "https://images.vexels.com/media/users/3/128927/isolated/preview/25652eb37d257753ffab9b4ac8edfa28-travel-airport-round-icon-arrow-by-vexels.png"][]
)
] |> move (72,-43.7) |> notifyTap msg
OK -> group [ html 30 36
( Html.img [Html.Attributes.width 30
, Html.Attributes.src "https://image.flaticon.com/icons/png/512/31/31287.png"][]
)
] |> move (-10,-35) |> notifyTap msg

NextQ -> group [ html 25 31
( Html.img [Html.Attributes.width 25
, Html.Attributes.src "https://www.westfield.ma.edu/PersonalPages/draker/edcom/final/webprojects/sp17/sectiona/madmoney/Next%20Button.png"][]
)
] |> move (50,-30) |> notifyTap msg

init = { time = 0 ,state = Start, graph1= False, graph2= False, graph3= False, graph4= False, graph5= False, commonMistakes1 = False,commonMistakes2 = False,commonMistakes3 = False
,commonMistakes4 = False,commonMistakes5 = False, correct1 = False, correct2 = False,correct3 = False, correct4 = False,correct5 = False,incorrect1 = False, incorrect2 = False, incorrect3 = False
, incorrect4 = False, incorrect5 = False}

type alias Model =
{ time : Float
, state : State
, graph1 : Bool
, graph2 : Bool
, graph3 : Bool
, graph4 : Bool
, graph5 : Bool
, commonMistakes1 : Bool
, commonMistakes2 : Bool
, commonMistakes3 : Bool
, commonMistakes4 : Bool
, commonMistakes5 : Bool
, correct1 : Bool
, correct2 : Bool
, correct3 : Bool
, correct4 : Bool
, correct5 : Bool
, incorrect1 : Bool
, incorrect2 : Bool
, incorrect3 : Bool
, incorrect4 : Bool
, incorrect5 : Bool
}

title = group [roundedRect 500 20 1 |>filled blue|>move(0,5),
text "LINEAR WORD PROBLEMS" |>filled black]
-- Hint box for the different questions
hints1=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes1 ,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph1,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes1,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph1
]

hints2=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes2,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph2,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes2,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph2
]

hints3=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes3,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph3,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes3,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph3
]

hints4=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes4,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph4,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes4,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph4
]

hints5=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes5 ,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph5,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes5,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph5
]

-- The questions for each level
question1 = group
[
text "Question 1"
|> filled black
|> move (-55,44)
, text "Tickets for a play were $2 each and 4$ each for each adult. "
|> filled black
|> scale 0.4
|> move (-65,32)
, text "At one showing of the play, one adult brought 4 children "
|> filled black
|> scale 0.4
|> move (-65,26)
, text "and the remaining adults brought 2 children each. The total "
|> filled black
|> scale 0.4
|> move (-65,20)
, text "ticket sales from the children and adults was $60."
|> filled black
|> scale 0.4
|> move (-65,14)
, text "How many children and adults attended the play"
|> filled black
|> scale 0.4
|> move (-65,8)

]
question2 = group
[
text "Question 2"
|> filled black
|> move (-55,44)
, text "Oceanside Bike Rental Shop charges 14 dollars "
|> filled black
|> scale 0.4
|> move (-65,32)
, text "plus 8 dollars an hour for renting a bike. "
|> filled black
|> scale 0.4
|> move (-65,26)
, text "Benny paid 78 dollars to rent a bike. How many "
|> filled black
|> scale 0.4
|> move (-65,20)
, text "hours did he pay to have the bike checked out?"
|> filled black
|> scale 0.4
|> move (-65,14)
]
question3 = group
[
text "Question 3"
|> filled black
|> move (-55,44)
, text "Kaspar has a total of 100 red and green jelly beans."
|> filled black
|> scale 0.4
|> move (-65,32)
, text "Three times the number of red, decreased by 3 "
|> filled black
|> scale 0.4
|> move (-65,26)
, text "equals double the number of green, increased by 2."
|> filled black
|> scale 0.4
|> move (-65,20)
, text "How many of each colour are there?"
|> filled black
|> scale 0.4
|> move (-65,14)
]
question4 = group
[
text "Question 4"
|> filled black
|> move (-55,44)
, text "The average speed of a bus is 8 times the average."
|> filled black
|> scale 0.4
|> move (-65,32)
, text "speed of a bike. The bike covers 186 km in 3 hours"
|> filled black
|> scale 0.4
|> move (-65,26)
, text "On a sunny day in July, how much distance will the "
|> filled black
|> scale 0.4
|> move (-65,20)
, text "bus cover in 10 hours?"
|> filled black
|> scale 0.4
|> move (-65,14)
]
question5 = group
[
text "Question 5"
|> filled black
|> move (-55,44)
, text "A bike messenger delivers a package from a farm to"
|> filled black
|> scale 0.4
|> move (-65,32)
, text "the city, travelling at an average speed of 24 km/hour."
|> filled black
|> scale 0.4
|> move (-65,26)
, text "On the way back, the messenger got stuck in traffic which"
|> filled black
|> scale 0.4
|> move (-65,20)
, text "reduced his average speed for the return trip by 12.5%"
|> filled black
|> scale 0.4
|> move (-65,14)
, text "What was the messenger's average speed, for the whole trip?"
|> filled black
|> scale 0.4
|> move (-65,8)
]
imageUrl = "https://images.all-free-download.com/images/graphiclarge/old_style_border_54668.jpg"
backGround = move (-95,64.5) <| scale 0.315 <| html 5280 4200 <| Html.img [Html.Attributes.src imageUrl][]

highlight = rect 13 5
|> filled (rgb 222 244 64 )
-- The answer box for each level
answerBox1 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect1 -- You can try again if you get it wrong
|> notifyTap Wrong1,

text "18 children and 6 adults"
|> filled black
|> scale (0.4)
|> move (-30,11)
|> notifyTap Incorrect1
|> notifyTap Wrong1,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Correct1 -- You can move to the next question if u get it right
|> notifyTap Right1,

text "16 children and 7 adults"
|> filled black
|> scale (0.4)
|> move (-31,-11)
|> notifyTap Correct1
|> notifyTap Right1,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect1
|> notifyTap Wrong1,

text "14 children and 8 adults"
|> filled black
|> scale (0.4)
|> move (27,11)
|> notifyTap Incorrect1
|> notifyTap Wrong1,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect1
|> notifyTap Wrong1,

text "12 children and 9 adults"
|> filled black
|> scale (0.4)
|> move (27,-11)
|> notifyTap Incorrect1
|> notifyTap Wrong1


]

answerBox2 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Correct2
|> notifyTap Right2,

text "Paid for 8 hours"
|> filled black
|> scale (0.4)
|> move (-21,11)
|> notifyTap Correct2
|> notifyTap Right2,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Incorrect2
|> notifyTap Wrong2,

text "Paid for 10 hours"
|> filled black
|> scale (0.4)
|> move (-22,-11)
|> notifyTap Incorrect2
|> notifyTap Wrong2,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect2
|> notifyTap Wrong2,

text "Paid for 15 hours"
|> filled black
|> scale (0.4)
|> move (36,11)
|> notifyTap Incorrect2
|> notifyTap Wrong2,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect2
|> notifyTap Wrong2,

text "Paid for 23 hours"
|> filled black
|> scale (0.4)
|> move (36,-11)
|> notifyTap Incorrect2
|> notifyTap Wrong2


]

answerBox4 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect4
|> notifyTap Wrong4,

text "4050 km in distance"
|> filled black
|> scale (0.4)
|> move (-23,11)
|> notifyTap Incorrect4
|> notifyTap Wrong4,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Correct4
|> notifyTap Right4,

text "4960 km in distance"
|> filled black
|> scale (0.4)
|> move (-23,-11)
|> notifyTap Correct4
|> notifyTap Right4,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect4
|> notifyTap Wrong4,

text "3210 km in distance"
|> filled black
|> scale (0.4)
|> move (33,11)
|> notifyTap Incorrect4
|> notifyTap Wrong4,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect4
|> notifyTap Wrong4,

text "3050 km in distance"
|> filled black
|> scale (0.4)
|> move (33,-11)
|> notifyTap Incorrect4
|> notifyTap Wrong4


]

answerBox3 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "50 of each colour"
|> filled black
|> scale (0.4)
|> move (-21,11)
|> notifyTap Incorrect3
|> notifyTap Wrong3,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "60 Red and 40 Green"
|> filled black
|> scale (0.4)
|> move (-21,-11)
|> notifyTap Incorrect3
|> notifyTap Wrong3,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Correct3
|> notifyTap Right3,

text "41 Red and 59 Green"
|> filled black
|> scale (0.4)
|> move (35,11)
|> notifyTap Correct3
|> notifyTap Right3,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "55 Red and 45 Green"
|> filled black
|> scale (0.4)
|> move (35,-11)
|> notifyTap Incorrect3
|> notifyTap Wrong3


]
answerBox5 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect5
|> notifyTap Wrong5,

text "25.8 km per hour"
|> filled black
|> scale (0.4)
|> move (-22,11)
|> notifyTap Incorrect5
|> notifyTap Wrong5,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "20.1 km per hour"
|> filled black
|> scale (0.4)
|> move (-22,-11)
|> notifyTap Incorrect5
|> notifyTap Wrong5,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect5
|> notifyTap Wrong5,

text "29.5 km per hour"
|> filled black
|> scale (0.4)
|> move (35,11)
|> notifyTap Incorrect5
|> notifyTap Wrong5,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Correct5
|> notifyTap Right5,

text "22.4 km per hour"
|> filled black
|> scale (0.4)
|> move (35,-11)
|> notifyTap Correct5
|> notifyTap Right5


]

-- Assigning the different graphical representations for each linear word problem
graph1 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://useruploads.socratic.org/AXK0sR8EQqKwWBDC9l9P_x%20equals%206.bmp"][]
)
] |> move (-13,25)|>scale 1.35

graph2 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://useruploads.socratic.org/ZgnsRuQQ6KlYHBxjdwCW_plot-formula.mpl"][]
)
] |> move (-13,25)|>scale 1.35

graph3 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://i.stack.imgur.com/6Cqv4.png"][]
)
] |> move (-13,25)|>scale 1.35

graph4 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://www.algebra.com/cgi-bin/plot-formula.mpl?expression=graph%28+300%2C+200%2C+-20%2C+20%2C+-20%2C+20%2C+8x%29"][]
)
] |> move (-13,25)|>scale 1.35

graph5 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://cdn.kastatic.org/ka-perseus-graphie/93634f4fa404f622128d318e5c3b0cd546bf0420.svg"][]
)
] |> move (-13,25)|>scale 1.35

Norman's principles.pdf (145.18 KB) 
By: Jerica Dias   Submitted: Apr 9, 2021 3:07 PM    Norman's principles.pdf is Unread - Click to set as read Norman's principles.pdf is Not flagged - Click to flag
Comments
https://web.microsoftstream.com/video/83c3e0b0-3bcb-4cf9-9651-e306c5e3ef4c

https://docs.google.com/presentation/d/1U95lJXTnbrVWx_2tYfydyZL-3SCGsRNXO3yuTJvVSps/edit?usp=sharing

import Html
import Html.Attributes

imageUrl1 = "https://img.favpng.com/19/21/23/math-word-problems-mathematics-problem-solving-png-favpng-54qGjN1e1sEfDDS98SLh904Ph.jpg"
imageWidth = 1280
imageHeight = 1200
imageScale = 0.3
imageMove = (-30,15)
pic = move imageMove <| scale imageScale <| html imageWidth imageHeight <| Html.img [Html.Attributes.src imageUrl1][]
imageUrl2= "https://i.ytimg.com/vi/1cDbjMg2UNA/maxresdefault.jpg"
imageUrl3= "https://image.slidesharecdn.com/nonlinear-1207170428110019-8/95/animal-kingdom-10-728.jpg?cb=1207145388"

myShapes model =
case model.state of
Start ->
[
pic |>move(-90,-60) |>scale 0.4,
title |>move (-70,50),
transition Lev3 T1,
text "Level 3"
|> centered
|> filled black
|> scale 0.5
|> move (60.5,18.5)
|> notifyTap T1,
transition Lev2 T3,
text "Level 2"
|> filled black
|> scale 0.5
|> move (-9,18.5)
|> notifyTap T3,
transition Lev1 T5,
text "Level 1"
|> filled black
|> scale 0.5
|>move (-69,18.5)
|> notifyTap T5,


transition Lev4 T19,
text "Level 4"
|> filled black
|> scale 0.5
|>move (-39,-1.5)
|> notifyTap T19,
transition Lev5 T20,
text "Level 5"
|> filled black
|> scale 0.5
|>move (21,-1.5)
|> notifyTap T20
]
-- Designing each level for the word problems
Level1 ->
[ backGround,
hints1 |>move (65,32)
, answerBox1 |>move (-50,-31)
, highlight
|> move (-30,38)
, highlight
|> move (-38,38)
, highlight
|> move (-31,33)
, highlight
|> move (-50,28)
, highlight
|> move (-63,28)
, question1
|> scale 0.8
|> move (-30,12)
, if (model.graph1) then
graph1 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes1) then

group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. There is an adult who brought 2 children"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (30, 11)
else
text ""
|> filled black

,transition Home T6, -- Able to move to the home page from a level
transition Next T9 -- Able to move to the next level
]
Level2 ->
[ backGround,
hints2 |>move (65,32)
, answerBox2 |>move (-50,-31)
, highlight
|> move (-11.5,37.5)
|> scaleX 1.3
, highlight
|> move (-67,32)
, highlight
|> move (-45,27)
|> scaleX 1.2
, highlight
|> move (-96,22)
|> scaleX 0.8
, question2
|> scale 0.8
|> move (-29,10)
, if (model.graph2) then
graph2 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes2) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text " so you can isolate for 2 variables!"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (36, 11)
else
text ""
|> filled black
,
transition Home T4,
transition Back T8,
transition Next T10


]


Level3 ->
[ backGround,
hints3 |>move (65,32)
, answerBox3 |>move (-50,-31)
, highlight
|> move (-42.5,37)
, highlight
|> move (-51,22)
|> scaleX 0.85
, question3
|> scale 0.8
|> move (-29,10)
, if (model.graph3) then
graph3 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes3) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. Start with R + G = 100"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (36, 11)
else
text ""
|> filled black

, transition Home T2
, transition Back T7
, transition Next T10A

]
Level4 ->
[ backGround,
hints4 |>move (65,32)
, answerBox4 |>move (-50,-31)
, highlight
|> move (-28,37)
, highlight
|> move (-7,32)
, highlight
|> move (-24,32)
, highlight
|> move (-67,22)
|> scaleX 0.85
, question4
|> scale 0.8
|> move (-29,10)
, if (model.graph4) then
graph4 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes4) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. Start with y = 8x"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (36, 11)
else
text ""
|> filled black

, transition Home T4A
, transition Back T7A
, transition Next T10B

]
Level5 ->
[ backGround,
hints5 |>move (65,32)
, answerBox5 |>move (-50,-31)
, highlight
|> move (-13,32)
, highlight
|> move (-6,22)
|> scaleX 0.85
, question5
|> scale 0.8
|> move (-29,10)
, if (model.graph5) then
graph5 |> scale 0.65 |> move (43,-28)

else
text ""
|> filled black
, if (model.commonMistakes5) then
group [
text "1. Read the question carefully"
|> filled black
, text "2. Have a well defined statment"
|> filled black
|> move (0,-12)
, text "3. Remember to have 2 equations"
|> filled black
|> move (0,-24)
, text "4. Average speed=total_distance/total_time"
|> filled black
|> move (0,-36)
] |> scale 0.27 |> move (30, 11)
else
text ""
|> filled black

, transition Home T4B
, transition Back T7B

]
-- Assigning different messages when you get an answer wrong/right
RightAns1 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11A,
transition NextQ T16
]

RightAns2 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11B,
transition NextQ T17
]
RightAns3 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11C,
transition NextQ T17A
]
RightAns4 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11D,
transition NextQ T17B
]
RightAns5 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl3] [])
|> scale 0.27
|> move (-100,85)
] ,
transition Home T11E
]
WrongAns1 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12A
, transition OK T13

]
WrongAns2 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12B
, transition OK T14

]
WrongAns3 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12C
, transition OK T15

]
WrongAns4 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12D
, transition OK T15A

]
WrongAns5 -> [ group [ square 100
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.2
|> move (-120,85)
] ,
transition Home T12E
, transition OK T15B

]
-- using html to import pictures for backgrounds
background1 = group [ square 300
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl] [])
|> scale 0.15
|> move (-95,60)
]
background2 = group [ square 300
|> filled black,
(html 100000 10000 <| Html.img [Html.Attributes.src imageUrl2] [])
|> scale 0.15
|> move (-95,60)
]
type Msg = Tick Float GetKeyState
| T1
| T2
| T3
| T4
| T4A
| T4B
| T5
| T6
| T7
| T7A
| T7B
| T8
| T9
| T10
| T10A
| T10B
| T11A
| T11B
| T11C
| T11D
| T11E
| T12A
| T12B
| T12C
| T12D
| T12E
| T13
| T14
| T15
| T15A
| T15B
| T16
| T17
| T17A
| T17B
| T19
| T20
| Graph1
| Graph2
| Graph3
| Graph4
| Graph5
| CommonMistakes1
| CommonMistakes2
| CommonMistakes3
| CommonMistakes4
| CommonMistakes5
| Correct1
| Correct2
| Correct3
| Correct4
| Correct5
| Incorrect1
| Incorrect2
| Incorrect3
| Incorrect4
| Incorrect5
| Right1
| Right2
| Right3
| Right4
| Right5
| Wrong1
| Wrong2
| Wrong3
| Wrong4
| Wrong5

type State = Start
| Level5
| Level4
| Level3
| Level2
| Level1
| RightAns1
| RightAns2
| RightAns3
| RightAns4
| RightAns5
| WrongAns1
| WrongAns2
| WrongAns3
| WrongAns4
| WrongAns5



update msg model = case msg of
Tick t _ -> { model | time = t }

Graph1 -> if model.graph1 ==True then
{model | graph1 =False}
else
{model |graph1 =True}
Graph2 -> if model.graph2 ==True then
{model | graph2 =False}
else
{model |graph2 =True}
Graph3 -> if model.graph3 ==True then
{model | graph3 =False}
else
{model |graph3 =True}
Graph4 -> if model.graph4 ==True then
{model | graph4 =False}
else
{model |graph4 =True}
Graph5 -> if model.graph5 ==True then
{model | graph5 =False}
else
{model |graph5 =True}
CommonMistakes1 -> if model.commonMistakes1 ==True then
{model | commonMistakes1 =False}
else
{model |commonMistakes1 =True}

CommonMistakes2 -> if model.commonMistakes2 ==True then
{model | commonMistakes2 =False}
else
{model |commonMistakes2 =True}

CommonMistakes3 -> if model.commonMistakes3 ==True then
{model | commonMistakes3 =False}
else
{model |commonMistakes3 =True}
CommonMistakes4 -> if model.commonMistakes4 ==True then
{model | commonMistakes4 =False}
else
{model |commonMistakes4 =True}

CommonMistakes5 -> if model.commonMistakes5 ==True then
{model | commonMistakes5 =False}
else
{model |commonMistakes5 =True}
Correct1 -> if model.correct1 ==False && model.incorrect1 == False then
{model | correct1 =True}
else
{model |correct1 =False}

Correct2 -> if model.correct2 ==False && model.incorrect2 == False then
{model | correct2 =True}
else
{model |correct2 =False}

Correct3 -> if model.correct3 ==False && model.incorrect3 == False then
{model | correct3 =True}
else
{model |correct3 =False}
Correct4 -> if model.correct4 ==False && model.incorrect4 == False then
{model | correct4 =True}
else
{model |correct4 =False}

Correct5 -> if model.correct5 ==False && model.incorrect5 == False then
{model | correct5 =True}
else
{model |correct5 =False}
Incorrect1 -> if model.incorrect1 ==False && model.correct1 == False then
{model | incorrect1 =True}
else
{model |incorrect1 =False}
Incorrect2 -> if model.incorrect2 ==False && model.correct2 == False then
{model | incorrect2 =True}
else
{model |incorrect2 =False}
Incorrect3 -> if model.incorrect3 ==False && model.correct3 == False then
{model | incorrect3 =True}
else
{model |incorrect3 =False}
Incorrect4 -> if model.incorrect4 ==False && model.correct4 == False then
{model | incorrect4 =True}
else
{model |incorrect4 =False}
Incorrect5 -> if model.incorrect5 ==False && model.correct5 == False then
{model | incorrect5 =True}
else
{model |incorrect5 =False}
T1 ->
case model.state of
Start ->
{ model | state = Level3 }
otherwise ->
model
T2 ->
case model.state of
Level3 ->
{ model | state = Start }
otherwise ->
model
T3 ->
case model.state of
Start ->
{ model | state = Level2 }
otherwise ->
model
T4 ->
case model.state of
Level2 ->
{ model | state = Start }
otherwise ->
model
T4A ->
case model.state of
Level4 ->
{ model | state = Start }
otherwise ->
model
T4B ->
case model.state of
Level5 ->
{ model | state = Start }
otherwise ->
model
T5 ->
case model.state of
Start ->
{ model | state = Level1 }
otherwise ->
model
T6 ->
case model.state of
Level1 ->
{ model | state = Start }
otherwise ->
model

T7 ->
case model.state of
Level3 ->
{ model | state = Level2 }
otherwise ->
model

T7A ->
case model.state of
Level4 ->
{ model | state = Level3 }
otherwise ->
model

T7B ->
case model.state of
Level5 ->
{ model | state = Level4 }
otherwise ->
model
T8 ->
case model.state of
Level2 ->
{ model | state = Level1 }
otherwise ->
model
T9 ->
case model.state of
Level1 ->
{ model | state = Level2 }
otherwise ->
model
T10 ->
case model.state of
Level2 ->
{ model | state = Level3 }
otherwise ->
model
T10A ->
case model.state of
Level3 ->
{ model | state = Level4 }
otherwise ->
model
T10B ->
case model.state of
Level4 ->
{ model | state = Level5 }
otherwise ->
model
T11A ->
case model.state of
RightAns1 ->
{ model | state = Start }
otherwise ->
model
T11B ->
case model.state of
RightAns2 ->
{ model | state = Start }
otherwise ->
model
T11C ->
case model.state of
RightAns3 ->
{ model | state = Start }
otherwise ->
model
T11D ->
case model.state of
RightAns4 ->
{ model | state = Start }
otherwise ->
model
T11E ->
case model.state of
RightAns5 ->
{ model | state = Start }
otherwise ->
model
T12A ->
case model.state of
WrongAns1 ->
{ model | state = Start }
otherwise ->
model
T12B ->
case model.state of
WrongAns2 ->
{ model | state = Start }
otherwise ->
model
T12C ->
case model.state of
WrongAns3 ->
{ model | state = Start }
otherwise ->
model
T12D ->
case model.state of
WrongAns4 ->
{ model | state = Start }
otherwise ->
model
T12E ->
case model.state of
WrongAns5 ->
{ model | state = Start }
otherwise ->
model
T13 ->
case model.state of
WrongAns1 ->
{ model | state = Level1 }
otherwise ->
model
T14 ->
case model.state of
WrongAns2 ->
{ model | state = Level2 }
otherwise ->
model
T15 ->
case model.state of
WrongAns3 ->
{ model | state = Level3 }
otherwise ->
model
T15A ->
case model.state of
WrongAns4 ->
{ model | state = Level4 }
otherwise ->
model

T15B ->
case model.state of
WrongAns5 ->
{ model | state = Level5 }
otherwise ->
model
T16 ->
case model.state of
RightAns1 ->
{ model | state = Level2 }
otherwise ->
model
T17 ->
case model.state of
RightAns2 ->
{ model | state = Level3 }
otherwise ->
model
T17A ->
case model.state of
RightAns3 ->
{ model | state = Level4 }
otherwise ->
model
T17B ->
case model.state of
RightAns4 ->
{ model | state = Level5 }
otherwise ->
model
T19 ->
case model.state of
Start ->
{ model | state = Level4 }
otherwise ->
model
T20 ->
case model.state of
Start ->
{ model | state = Level5 }
otherwise ->
model

Right1 ->
case model.state of
Level1 ->
{ model | state = RightAns1 }
otherwise ->
model

Right2 ->
case model.state of
Level2 ->
{ model | state = RightAns2 }
otherwise ->
model
Right3 ->
case model.state of
Level3 ->
{ model | state = RightAns3 }
otherwise ->
model
Right4 ->
case model.state of
Level4 ->
{ model | state = RightAns4 }
otherwise ->
model
Right5 ->
case model.state of
Level5 ->
{ model | state = RightAns5 }
otherwise ->
model
Wrong1 ->
case model.state of
Level1 ->
{ model | state = WrongAns1 }
otherwise ->
model

Wrong2 ->
case model.state of
Level2 ->
{ model | state = WrongAns2 }
otherwise ->
model
Wrong3 ->
case model.state of
Level3 ->
{ model | state = WrongAns3 }
otherwise ->
model
Wrong4 ->
case model.state of
Level4 ->
{ model | state = WrongAns4 }
otherwise ->
model
Wrong5 ->
case model.state of
Level5 ->
{ model | state = WrongAns5 }
otherwise ->
model
background = group [
rect 200 300
|> filled (rgb 64 224 208)
]

-- Different button positions
type ButtonPosition = Lev1 | Lev2 | Lev3 | Lev4 | Lev5 | Home | Back | Next | OK | NextQ

transition : ButtonPosition -> Msg -> Shape Msg
transition pos msg = case pos of
Lev1 -> group [roundedRect 30 15 2
|> filled orange
] |> move (-60,20)
|> notifyTap msg

Lev2 -> group [roundedRect 30 15 2
|> filled orange
] |> move (0,20)
|> notifyTap msg
Lev3 -> group [roundedRect 30 15 2
|> filled orange
] |> move (60,20 )
|> notifyTap msg
Lev4 -> group [roundedRect 30 15 2
|> filled orange
] |> move (-30,0.5 )
|> notifyTap msg

Lev5 -> group [roundedRect 30 15 2
|> filled orange
] |> move (30,0.5 )
|> notifyTap msg

-- using html attributes to get certain symbols for the program
Home -> group [ html 10 16
( Html.img [Html.Attributes.width 10
, Html.Attributes.src "https://static.thenounproject.com/png/901844-200.png"][]
)
] |> move (-87,59.5) |> notifyTap msg
Back -> group [ html 10 16
( Html.img [Html.Attributes.width 10
, Html.Attributes.src "https://images.vexels.com/media/users/3/128927/isolated/preview/25652eb37d257753ffab9b4ac8edfa28-travel-airport-round-icon-arrow-by-vexels.png"][]
)
] |> rotate (degrees 180) |> move (70,-59.5) |> notifyTap msg
Next -> group [ html 10 16
( Html.img [Html.Attributes.width 10
, Html.Attributes.src "https://images.vexels.com/media/users/3/128927/isolated/preview/25652eb37d257753ffab9b4ac8edfa28-travel-airport-round-icon-arrow-by-vexels.png"][]
)
] |> move (72,-43.7) |> notifyTap msg
OK -> group [ html 30 36
( Html.img [Html.Attributes.width 30
, Html.Attributes.src "https://image.flaticon.com/icons/png/512/31/31287.png"][]
)
] |> move (-10,-35) |> notifyTap msg

NextQ -> group [ html 25 31
( Html.img [Html.Attributes.width 25
, Html.Attributes.src "https://www.westfield.ma.edu/PersonalPages/draker/edcom/final/webprojects/sp17/sectiona/madmoney/Next%20Button.png"][]
)
] |> move (50,-30) |> notifyTap msg

init = { time = 0 ,state = Start, graph1= False, graph2= False, graph3= False, graph4= False, graph5= False, commonMistakes1 = False,commonMistakes2 = False,commonMistakes3 = False
,commonMistakes4 = False,commonMistakes5 = False, correct1 = False, correct2 = False,correct3 = False, correct4 = False,correct5 = False,incorrect1 = False, incorrect2 = False, incorrect3 = False
, incorrect4 = False, incorrect5 = False}

type alias Model =
{ time : Float
, state : State
, graph1 : Bool
, graph2 : Bool
, graph3 : Bool
, graph4 : Bool
, graph5 : Bool
, commonMistakes1 : Bool
, commonMistakes2 : Bool
, commonMistakes3 : Bool
, commonMistakes4 : Bool
, commonMistakes5 : Bool
, correct1 : Bool
, correct2 : Bool
, correct3 : Bool
, correct4 : Bool
, correct5 : Bool
, incorrect1 : Bool
, incorrect2 : Bool
, incorrect3 : Bool
, incorrect4 : Bool
, incorrect5 : Bool
}

title = group [roundedRect 500 20 1 |>filled blue|>move(0,5),
text "LINEAR WORD PROBLEMS" |>filled black]
-- Hint box for the different questions
hints1=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes1 ,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph1,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes1,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph1
]

hints2=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes2,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph2,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes2,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph2
]

hints3=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes3,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph3,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes3,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph3
]

hints4=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes4,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph4,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes4,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph4
]

hints5=group[
rect 48 18 |> filled grey |> move (-6,13) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap CommonMistakes5 ,
rect 48 18 |> filled grey |> move(-6,-5) |> makeTransparent 0.3 |> addOutline(solid 0.5) grey |> notifyTap Graph5,
text "HINTS" |> filled black |>move (-32,20) |>scale 0.5 |> notifyTap CommonMistakes5,
text "Graphical Representation" |> filled black |>move (-79,-14) |>scale 0.37 |> notifyTap Graph5
]

-- The questions for each level
question1 = group
[
text "Question 1"
|> filled black
|> move (-55,44)
, text "Tickets for a play were $2 each and 4$ each for each adult. "
|> filled black
|> scale 0.4
|> move (-65,32)
, text "At one showing of the play, one adult brought 4 children "
|> filled black
|> scale 0.4
|> move (-65,26)
, text "and the remaining adults brought 2 children each. The total "
|> filled black
|> scale 0.4
|> move (-65,20)
, text "ticket sales from the children and adults was $60."
|> filled black
|> scale 0.4
|> move (-65,14)
, text "How many children and adults attended the play"
|> filled black
|> scale 0.4
|> move (-65,8)

]
question2 = group
[
text "Question 2"
|> filled black
|> move (-55,44)
, text "Oceanside Bike Rental Shop charges 14 dollars "
|> filled black
|> scale 0.4
|> move (-65,32)
, text "plus 8 dollars an hour for renting a bike. "
|> filled black
|> scale 0.4
|> move (-65,26)
, text "Benny paid 78 dollars to rent a bike. How many "
|> filled black
|> scale 0.4
|> move (-65,20)
, text "hours did he pay to have the bike checked out?"
|> filled black
|> scale 0.4
|> move (-65,14)
]
question3 = group
[
text "Question 3"
|> filled black
|> move (-55,44)
, text "Kaspar has a total of 100 red and green jelly beans."
|> filled black
|> scale 0.4
|> move (-65,32)
, text "Three times the number of red, decreased by 3 "
|> filled black
|> scale 0.4
|> move (-65,26)
, text "equals double the number of green, increased by 2."
|> filled black
|> scale 0.4
|> move (-65,20)
, text "How many of each colour are there?"
|> filled black
|> scale 0.4
|> move (-65,14)
]
question4 = group
[
text "Question 4"
|> filled black
|> move (-55,44)
, text "The average speed of a bus is 8 times the average."
|> filled black
|> scale 0.4
|> move (-65,32)
, text "speed of a bike. The bike covers 186 km in 3 hours"
|> filled black
|> scale 0.4
|> move (-65,26)
, text "On a sunny day in July, how much distance will the "
|> filled black
|> scale 0.4
|> move (-65,20)
, text "bus cover in 10 hours?"
|> filled black
|> scale 0.4
|> move (-65,14)
]
question5 = group
[
text "Question 5"
|> filled black
|> move (-55,44)
, text "A bike messenger delivers a package from a farm to"
|> filled black
|> scale 0.4
|> move (-65,32)
, text "the city, travelling at an average speed of 24 km/hour."
|> filled black
|> scale 0.4
|> move (-65,26)
, text "On the way back, the messenger got stuck in traffic which"
|> filled black
|> scale 0.4
|> move (-65,20)
, text "reduced his average speed for the return trip by 12.5%"
|> filled black
|> scale 0.4
|> move (-65,14)
, text "What was the messenger's average speed, for the whole trip?"
|> filled black
|> scale 0.4
|> move (-65,8)
]
imageUrl = "https://images.all-free-download.com/images/graphiclarge/old_style_border_54668.jpg"
backGround = move (-95,64.5) <| scale 0.315 <| html 5280 4200 <| Html.img [Html.Attributes.src imageUrl][]

highlight = rect 13 5
|> filled (rgb 222 244 64 )
-- The answer box for each level
answerBox1 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect1 -- You can try again if you get it wrong
|> notifyTap Wrong1,

text "18 children and 6 adults"
|> filled black
|> scale (0.4)
|> move (-30,11)
|> notifyTap Incorrect1
|> notifyTap Wrong1,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Correct1 -- You can move to the next question if u get it right
|> notifyTap Right1,

text "16 children and 7 adults"
|> filled black
|> scale (0.4)
|> move (-31,-11)
|> notifyTap Correct1
|> notifyTap Right1,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect1
|> notifyTap Wrong1,

text "14 children and 8 adults"
|> filled black
|> scale (0.4)
|> move (27,11)
|> notifyTap Incorrect1
|> notifyTap Wrong1,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect1
|> notifyTap Wrong1,

text "12 children and 9 adults"
|> filled black
|> scale (0.4)
|> move (27,-11)
|> notifyTap Incorrect1
|> notifyTap Wrong1


]

answerBox2 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Correct2
|> notifyTap Right2,

text "Paid for 8 hours"
|> filled black
|> scale (0.4)
|> move (-21,11)
|> notifyTap Correct2
|> notifyTap Right2,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Incorrect2
|> notifyTap Wrong2,

text "Paid for 10 hours"
|> filled black
|> scale (0.4)
|> move (-22,-11)
|> notifyTap Incorrect2
|> notifyTap Wrong2,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect2
|> notifyTap Wrong2,

text "Paid for 15 hours"
|> filled black
|> scale (0.4)
|> move (36,11)
|> notifyTap Incorrect2
|> notifyTap Wrong2,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect2
|> notifyTap Wrong2,

text "Paid for 23 hours"
|> filled black
|> scale (0.4)
|> move (36,-11)
|> notifyTap Incorrect2
|> notifyTap Wrong2


]

answerBox4 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect4
|> notifyTap Wrong4,

text "4050 km in distance"
|> filled black
|> scale (0.4)
|> move (-23,11)
|> notifyTap Incorrect4
|> notifyTap Wrong4,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Correct4
|> notifyTap Right4,

text "4960 km in distance"
|> filled black
|> scale (0.4)
|> move (-23,-11)
|> notifyTap Correct4
|> notifyTap Right4,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect4
|> notifyTap Wrong4,

text "3210 km in distance"
|> filled black
|> scale (0.4)
|> move (33,11)
|> notifyTap Incorrect4
|> notifyTap Wrong4,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect4
|> notifyTap Wrong4,

text "3050 km in distance"
|> filled black
|> scale (0.4)
|> move (33,-11)
|> notifyTap Incorrect4
|> notifyTap Wrong4


]

answerBox3 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "50 of each colour"
|> filled black
|> scale (0.4)
|> move (-21,11)
|> notifyTap Incorrect3
|> notifyTap Wrong3,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "60 Red and 40 Green"
|> filled black
|> scale (0.4)
|> move (-21,-11)
|> notifyTap Incorrect3
|> notifyTap Wrong3,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Correct3
|> notifyTap Right3,

text "41 Red and 59 Green"
|> filled black
|> scale (0.4)
|> move (35,11)
|> notifyTap Correct3
|> notifyTap Right3,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "55 Red and 45 Green"
|> filled black
|> scale (0.4)
|> move (35,-11)
|> notifyTap Incorrect3
|> notifyTap Wrong3


]
answerBox5 = group [


roundedRect 55 20 1
|> filled lightRed
|> makeTransparent 0.6
|> move (-5, 12)
|> notifyTap Incorrect5
|> notifyTap Wrong5,

text "25.8 km per hour"
|> filled black
|> scale (0.4)
|> move (-22,11)
|> notifyTap Incorrect5
|> notifyTap Wrong5,


roundedRect 55 20 1
|> filled lightYellow
|> makeTransparent 0.6
|> move (-5, -10)
|> notifyTap Incorrect3
|> notifyTap Wrong3,

text "20.1 km per hour"
|> filled black
|> scale (0.4)
|> move (-22,-11)
|> notifyTap Incorrect5
|> notifyTap Wrong5,


roundedRect 55 20 1
|> filled (rgb 0 102 204)
|> makeTransparent 0.6
|> move (52, 12)
|> notifyTap Incorrect5
|> notifyTap Wrong5,

text "29.5 km per hour"
|> filled black
|> scale (0.4)
|> move (35,11)
|> notifyTap Incorrect5
|> notifyTap Wrong5,



roundedRect 55 20 1
|> filled lightGreen
|> makeTransparent 0.5
|> move (52, -10)
|> notifyTap Correct5
|> notifyTap Right5,

text "22.4 km per hour"
|> filled black
|> scale (0.4)
|> move (35,-11)
|> notifyTap Correct5
|> notifyTap Right5


]

-- Assigning the different graphical representations for each linear word problem
graph1 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://useruploads.socratic.org/AXK0sR8EQqKwWBDC9l9P_x%20equals%206.bmp"][]
)
] |> move (-13,25)|>scale 1.35

graph2 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://useruploads.socratic.org/ZgnsRuQQ6KlYHBxjdwCW_plot-formula.mpl"][]
)
] |> move (-13,25)|>scale 1.35

graph3 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://i.stack.imgur.com/6Cqv4.png"][]
)
] |> move (-13,25)|>scale 1.35

graph4 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://www.algebra.com/cgi-bin/plot-formula.mpl?expression=graph%28+300%2C+200%2C+-20%2C+20%2C+-20%2C+20%2C+8x%29"][]
)
] |> move (-13,25)|>scale 1.35

graph5 = group [ html 62 82
( Html.img [Html.Attributes.width 62
, Html.Attributes.src "https://cdn.kastatic.org/ka-perseus-graphie/93634f4fa404f622128d318e5c3b0cd546bf0420.svg"][]
)
] |> move (-13,25)|>scale 1.35