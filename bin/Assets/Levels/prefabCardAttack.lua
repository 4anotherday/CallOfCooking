prefab = {}
prefab[0] = { Name = "CardAttack_"}
prefab[1] = { Component = "Transform", Coord = {X = 0, Y = -300, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=4,Y=.1,Z=2.3}}
prefab[2] = { Component = "ButtonComponent", OverLayName ="GameUI", Active = true, 
				ContainerName = "GameUI/RedCard", DefaultMaterial ="CallOfCooking/attackBase", HoverMaterial = "CallOfCooking/attackHover", PressMaterial = "CallOfCooking/attackPress"}
prefab[3] = { Component = "AttackSpeedCardComponent"}
prefab[4] = { Component = "AudioSource", Route = {"Assets/Audio/button.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = 0, Stereo = false, Play = false}