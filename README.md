# Tic-Tac-Toe in C++

# Introduction
This is a simple Tic-Tac-Toe made with C++ that can be built with CMake and ran conveniently on the local machine of the user.

The code is built in a way that doesn't require extra dependencies or packages and should be platform independent (because of that, there are some weird mechanics in terms of how the player moves their cursor on the screen).

# Premisse

The game is played agains an AI and the player is exposed to several terminal outputs:

## For Game Greetings

```terminal
 ____  __  ___     ____  __    ___     ____  __  ____ 
(_  _)(  )/ __)___(_  _)/ _\  / __)___(_  _)/  \(  __)
  )(   )(( (__(___) )( /    \( (__(___) )( (  O )) _)
 (__) (__)\___)    (__)\_/\_/ \___)    (__) \__/(____)
```

## When Playing:

Area chosen by the player will be highlighted in red

```terminal
_O_ | _O_ | _X_
___ | _X_ | ___
___ | _X_ | _O_
Move around with [W], [S], [A], [D]. Select space with [X]: 

```

## Player Winning:
```terminal
_O_ | _O_ | _X_
___ | _X_ | ___
_X_ | _X_ | _O_

 __    __ _                             ___ _                       
/ / /\ \ (_)_ __  _ __   ___ _ __ _    / _ \ | __ _ _   _  ___ _ __ 
\ \/  \/ / | '_ \| '_ \ / _ \ '__(_)  / /_)/ |/ _` | | | |/ _ \ '__|
 \  /\  /| | | | | | | |  __/ |   _  / ___/| | (_| | |_| |  __/ |
  \/  \/ |_|_| |_|_| |_|\___|_|  (_) \/    |_|\__,_|\__, |\___|_|
                                                    |___/     

```

## Computer Winning:
```terminal
_X_ | _O_ | _O_
_X_ | _O_ | _X_
_O_ | ___ | _X_

 __    __ _                             _     _____ 
/ / /\ \ (_)_ __  _ __   ___ _ __ _    /_\    \_   \ 
\ \/  \/ / | '_ \| '_ \ / _ \ '__(_)  //_\\    / /\/
 \  /\  /| | | | | | | |  __/ |   _  /  _  \/\/ /
  \/  \/ |_|_| |_|_| |_|\___|_|  (_) \_/ \_/\____/

```
