Hello and welcome to my journey of me implementing a chess game (and hopefully my own AI) in C++.


I am a student at University of Transilvania from Brasov Computer Science and I just finished my first year there. I started this project because I wanted to try my knowledge of this language as well as a form of exercise through the summer vacation.

On 25.07.2025 I implemented a base abstract class "Piece" as well as derived classes "Pawn", "Bishop", "Knight", "Rook", "Queen" and "King" together with an independent class "Board".
I am using the standard FIDE notations for the pieces ('N' for Knight, 'B' for Bishop, 'R' for Rook, 'Q' for Queen and 'K' for King) except for the pawns.
I used headers and forward declaration. I also implemented setBoard() and showBoard() functions, which allow me to set the board up for the game and show it to the user through the terminal.

<img width="190" height="201" alt="image" src="https://github.com/user-attachments/assets/1cac3bcc-cf58-4c17-959a-bdac86dc9d88" />


The capital letters are the white pieces and the other the black pieces.


On 26.07.2025 I implemented pawn movement logic (for both white and black). That includes diagonal captures, forward movement 1 square and 2 (on first move).
The upcoming images showcase the movement possibilities for the d2 pawn.

<img width="185" height="231" alt="image" src="https://github.com/user-attachments/assets/ba6f51a2-6080-44aa-b68c-424dd7e342a3" /> <img width="188" height="229" alt="image" src="https://github.com/user-attachments/assets/46e29d3a-dfe0-49fd-8915-c7254f7ac3df" /> <img width="190" height="235" alt="image" src="https://github.com/user-attachments/assets/e1092c3c-4313-4e60-bc63-943659c8feb6" /> <img width="181" height="232" alt="image" src="https://github.com/user-attachments/assets/d7e67e80-04e1-40d2-baa1-4cdeb4bd43c4" />
<img width="193" height="235" alt="image" src="https://github.com/user-attachments/assets/1afc8d45-e503-4fa4-af4f-341ef7702ec6" /> <img width="180" height="226" alt="image" src="https://github.com/user-attachments/assets/93eec237-b749-4853-b1db-b89aebda4806" />

As well for the black pawns (d7)

<img width="179" height="233" alt="image" src="https://github.com/user-attachments/assets/1740dda6-a317-4e54-8b9b-2583d62febcc" /> <img width="193" height="233" alt="image" src="https://github.com/user-attachments/assets/8f2620ea-bab6-468b-9472-c53434eaa52c" /> <img width="181" height="233" alt="image" src="https://github.com/user-attachments/assets/e1489516-a848-42b7-8113-e46309e316ac" />





On 28.07.2025 I implemented the movement logic for Bishops.

<img width="263" height="233" alt="image" src="https://github.com/user-attachments/assets/f2b879df-ddc2-4c0e-89f0-a02841a66b41" /> <img width="219" height="236" alt="image" src="https://github.com/user-attachments/assets/13c97b6b-806b-4a3a-84b6-9b0a08139726" />
<img width="197" height="232" alt="image" src="https://github.com/user-attachments/assets/299e300f-4f1e-4341-a0e9-c0d5518dc1c1" /> <img width="195" height="232" alt="image" src="https://github.com/user-attachments/assets/61974b0d-a8ce-44ed-9f37-551b56a38b99" />


<img width="185" height="233" alt="image" src="https://github.com/user-attachments/assets/5c636599-2bb8-4322-806b-36dd0109723a" />



For the nearby future I want to implement the movement logic for the remaining pieces.


