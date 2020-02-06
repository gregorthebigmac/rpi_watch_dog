# More Specific Syntax for settings.cfg

The settings.cfg file is extremely minimalistic. It will allow for comments. Comments will begin with a '#' and anything following this character will be ignored! This is pretty standard convention for Linux config files, so why fix what isn't broken? Just in case the above wasn't clear enough, here are examples of what will and will not work. The first block of examples are perfectly fine. Side note: Tabs are fine, tons of spaces are fine. ALL white space is ignored, except for the first space after the hostname, which is used to determine when the hostname stops and the IP address begins.

    server1     127.0.0.1   # This is the server in the basement
    server-2 192.168.1.1 # This is the server in the broom closet that keeps overheating for some reason.
    # This server is the one in the fish tank that accidentally killed our goldfish.
    server_3            10.42.0.1

Examples of things that you might think would work, but will not:

    # This is the server under my bed (keeps away the monsters)
    server 1        127.0.0.1   # The space between "server" and "1" will result in "server" being assigned an address of "1"
    # Comments in the MIDDLE of the entry are NOT allowed
    server-2 #This is the SUPER Noisy server we keep in the attic to keep the raccoons and squirrels out.#   192.168.1.1
    # If a line *begins* with a comment, the entire line is ignored.
    # This is the outdoor server that I weather-proofed. Unfortunately, I didn't make it bird-proof, and now there's a nest in there, and the city says I can't remove the nest until they move on their own. # server_3 10.42.0.1

