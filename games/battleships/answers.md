# Battleships Buggy Lab — Answers

## Team
- Team name:
- Partner A: Alex
- Partner B: Jiaqu

---

## 1) Requirement → Code Map (spec verification)

Fill this table by reading `games/battleships/specification.md` and mapping requirements to code.

Requirement (from specification.md) | Pass/Fail/Unsure | Code location (file + class/function) | Notes (what it does)
---|---|---|---
Example: Turns alternate after each valid shot |  | `battleships_buggy/src/core/Game.cpp` → `Game::AdvanceTurn` | flips current player index
Example: Tracking board records shots |  | `battleships_buggy/src/core/Game.cpp` → `Game::ShootAtOpponent` | updates `Player::tracking`

Add rows for all major requirements you verify.

---

## 2) Spec verification summary

Write Pass/Fail/Unsure for each area and explain *how you verified it* (test steps or observation).

- Setup phase:
- Placement rules:
- Input commands:
- Shot resolution:
- Tracking board:
- Win condition:

---

## 3) Bugs found (at least 6 total)

You must list at least:
- 3 functional bugs (incorrect behavior vs spec)
- 3 robustness issues (bad input handling, silent failures, crashes, etc.)

### Bug 1
- Symptom: You can place the last part of a ship on top of another ship vertically
- Steps to reproduce (exact inputs): place a ship on b3 and then a 3+ long ship on b1 vertically
- Expected (spec): you fail to place the ship
- Actual: it places the ship
- Suspected root cause (file/function): Board::CanPlaceShip
- Fix approach: removing the -1 from vertical orientation

### Bug 2
- Symptom: Player 2 can not place their ships
- Steps to reproduce (exact inputs): Place app of player 1s ships
- Expected (spec): Player 2 gets to place their ships
- Actual: Game starts with player 2 having 0 ships
- Suspected root cause (file/function): Game::FinishSetupIfReady()
- Fix approach: adding a check in the if to see if player 2 has placed any ships

### Bug 3
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 4
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 5
- Symptom: The game cannot distinguish between overlap and out-of-bounds accurately
- Steps to reproduce (exact inputs): both placing a ship out-of-bounds and placing a ship on top of another ship return the same PlaceResult
- Expected (spec): They should return different PlaceResult
- Actual: It returns the same thing
- Suspected root cause (file/function): it didn't check the InBounds
- Fix approach: Check if the ship is in bounds before checking if CanPlaceShip

### Bug 6
- Symptom: The console message was not informative when player failed to place a ship (spec asks to distinguish OutOfBounds vs Overlap).
- Steps to reproduce (exact inputs): place a ship on top of another ship or place a ship out-of-bounds
- Expected (spec): the console message should be informative (specifiy what's the reason)
- Actual: it output "Could not place ship. (buggy message, no detail)\n";
- Suspected root cause (file/function): it didn't implement the PlaceResult message convertion function
- Fix approach: implement it so it output the actual reason for stopping the player to place the ship

(Add more if you find more.)

---

## 4) Code smells found (at least 5)

A “smell” is not necessarily a bug, but a design/implementation choice that increases risk or cost.

### Smell 1
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 2
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 3
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 4
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 5
- What (where in code):
- Why risky:
- Better approach (short plan):

---

## 5) Good patterns found (at least 4)

Find at least 4 things the code does reasonably well.

### Good thing 1
- Where:
- Why good:
- How to reuse:

### Good thing 2
- Where:
- Why good:
- How to reuse:

### Good thing 3
- Where:
- Why good:
- How to reuse:

### Good thing 4
- Where:
- Why good:
- How to reuse:

---

## 6) Team bug-fix PR (pair programming)

- Branch name:
- PR link:
- Bugs fixed (list):
- Tests added/updated:
- How you verified the fixes:
- What you learned:

---

## 7) Team feature PR (pair programming)

- Feature implemented (from spec’s “Explicit Missing Features”):
- Branch name:
- PR link:

Mini-spec (write BEFORE coding):
- Behavior:
- Edge cases:
- How to verify (test or manual steps):

Verification performed:
- Tests/manual steps used:
- Result:

---

## 8) Individual feature PRs

### Partner A
- Feature:
- Branch:
- PR link:

Mini-spec:
- Behavior:
- Edge cases:
- How to verify:

Verification performed:
- Tests/manual steps used:
- Result:

### Partner B
- Feature:
- Branch:
- PR link:

Mini-spec:
- Behavior:
- Edge cases:
- How to verify:

Verification performed:
- Tests/manual steps used:
- Result:

---

## 9) Manual test script (if needed)

If you could not write tests for some behavior, write a reproducible manual test script.

Example format:
1) Start game
2) Place ships for both players with valid placements
3) Player 1 shoots A1 → expect: Miss/Hit/Sunk
4) Player 1 shoots A1 again → expect: AlreadyTried and turn should NOT change