# Vac-Bypass

### What does it do?
Blocks checking process priveleges
Blocks checking open system handles
Blocks checks of process signatures
Blocks interaction with any potential cheat programmes
Blocks ability to find modules loaded into any process
Blocks ability to find processes loaded onto the system
Blocks VAC from checking for executable cheat memory in itself and the game it is protecting

### How to inject
Run steam as administrator this is so that steamservice.exe isn't loaded instead the steamservice.dll (VAC) is loaded into steam.exe

You must have an injector dll x86
Then inject the bypass into steam.exe. After this you can start the VAC secured game
