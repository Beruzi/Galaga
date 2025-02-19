# Galaga

This is a remake of the 80's arcade game, Galaga. Built using SDL2, I am pursuing this project because I thought it would be a fun way expand upon my C++ knowledge, get some C-style experience in as well (SDL2 is a C-Style API), and have a local game I can play when I'm bored. 



----------------------------------------------------------------------------------------
##### Things to add:
- [ ] Fix our SSH so we can push changes to github... idk i think I messed something up in my config file while configuring my other ssh key for school & google cloud
- [ ] Normalize the diagonal speed... currently diagonal speed is faster than the horizontal and vertical speed.... THIS IS FOR BOTH THE MISSILES AND PLAYER/ALIENS

- [ ] Add Collision... create the Collision System and make the necessary adjustments to the other managers to register the collisions
    - It's also a chance to dabble in polymorphic behavior... the 2D Vector of aliens will be of the alien type, however the aliens themselves are the subtypes. So the 2D vector can be treated as aliens generaically but we can impose the specific functionality depending on the derived class of alien. 
        - ie the boss doesn't shoot missiles but has the tractor beam thing
- [ ] Figure out how to get the layout of the aliens... could use some enum and hardcode a layout
    - something like the following where we populate the 2D vecetor given the symbol:
```
                [O O O O O]
                [  B B B  ]
                [A A A A A]
```
- [ ] Rotate the sprites... the aliens orientation depends on the direction they're moving, the missiles should point in the direction they're travelling

- [ ] For collisions, add the destruction animation using the explosion sprites

- [ ] We have the precursor to game state already defined... finish it up...
    - Adding a menu screen
    - Adding the pause and unpause behavior
    - the quick escpae pop if the 'escape' key is presssed
    - etc.
