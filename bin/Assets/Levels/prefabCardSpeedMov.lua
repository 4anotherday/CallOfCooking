prefab = {}
prefab[0] = { Name = "CardSpeed_"}
prefab[1] = { Component = "Transform", Coord = {X = 0, Y = -300, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=4,Y=.1,Z=2.3}}
prefab[2] = { Component = "ButtonComponent", OverLayName ="GameUI", Active = true, 
				ContainerName = "GameUI/BlueCard", DefaultMaterial ="CallOfCooking/speedBase", HoverMaterial = "CallOfCooking/speedHover", PressMaterial = "CallOfCooking/speedPress"}
prefab[3] = { Component = "MovementSpeedCardComponent"}
prefab[4] = { Component = "AudioSource", Route = {"Assets/Audio/button.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = 0, Stereo = false, Play = false}