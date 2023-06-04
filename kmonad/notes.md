# A Guide To KMonad

## Intro

### Home Row Mods

This term refers to placing modifiers or "mods" in the home row 
of your keyboard. In an English QWERTY keyboard, this
corresponds to `ASDFGHJKL;`.

Modifers on the other hand, refer to any key, which,
when pressed, changes the functionality of another key.
The most commonly used modifiers are `Shift`(S), `Control`(C\),
`Alt` (A), and `GUI`(G) - also known as windows key, command key,
and super key on windows, macOS, and linux respectively.

Why would someone want this functionality? Because it enhances
the accessibility to modifiers by putting them in the home row.
This can be a considerable advantage if you are a vim or emacs 
user or if you use these modifiers often for various reasons.
Furthermore, it also has the direct benefit of reducing unnatural
movements which increase the risk of developing conditions such
RSI and Carpal Tunnel.

It is vital to understand that we will not "swap" the modifiers
with the keys on the home row. In other words, we will not have
to press `Control` to press `A` and vice versa. What happens is
that the home row keys act as their normal self when tapped and
as modifiers when held. This is the fundamental idea which we 
will explore in more detail.

## Order Matters

Having understood the fundamental idea behing home row mods, we 
need to decide how many modifiers to place on the home row and 
in what order. 

The answer to the first question depends on a case by case basis as 
different users will have different necessitites and may not frequently 
use all the modifiers. 

In this guide, we will analyze the scenario in which we want to place all 
four modifiers in the home row. A subtle, but important note, is that 
we will need to place the four modifiers twice: on the left and on the right.
Why? Suppose we put the `Shift` modifier on the `A` key. Now, by holding `A`
and pressing another key, we can obtain the shortcut `Shift-key`. But 
what if we want to press `Shift-A` to capitalize A? With only four home row 
modifiers, this combination is unavailable and we have to resort to the actual 
modifers, which is what we wanted to avoid in the first place!

So we solve this by placing another `Shift` modifier somewhere in the home row:
say at `;`. Now, to achieve `Shift-A`, we hold `;` and press `A`.
Analogously, to obtain `Shift-;` we hold `A` and press `;`. Easy!

So now, we have understood that if we want to place all four modifers,
we must actually place 8 in total.

But in what order should they be placed? Should they be symmetric? 
And does all this even matter? 
Turns out that the answer is yes. In fact, the ordering is so important 
that popular combinations have been analyzed at length and have caused much 
debate. 

Below we will discuss some possibilities. 

### SCGA

This layout mirrors the position of the origial modifiers.
Conceptually, this layout is slightly easier to get used to since
the relative positions of the modifiers are similar to what we are
used to, although we will need different fingers to activate them.

This layout gives a strong position to the `Gui` and `Alt` modifiers by 
assigning strong fingers to them. On the other hand, it gives less priority
to `Shift` and `Ctrl` since the weaker pinky and ring fingers are in charge
of these keys, respectively.

Pros:
    - Easy to get used to on a conceptual level.
    - A strong choice for users that use `Gui` and `Alt` often.
Cons:
    - Not suitable for users who use a lot of shortcuts with `Shift` modifier.


### GASC 

This layout gives a stronger role to `Shift` and `Ctrl` which are two of the 
most frequently used modifiers. In fact, if we rank the modifiers by their 
frequency for predefined shortcuts (not considering Vim or Emacs), then the order 
would be `GUI` < `Alt` < `Control` < `Shift`

So, we are assigning modifiers to increasingly stronger fingers based on their 
frequency of usage. Note however, that `Shift` and `Control` are swapped.

The main justification for this idea is that putting `Shift` between `Alt` and
`Control` enables us to hit all joint combinations `Alt + Shift`, `Ctrl+Shift`
comfortably.


