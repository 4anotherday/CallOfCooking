prefab = {}
prefab[0] = { Name = "CardAttack"}
prefab[1] = { Component = "Transform", Coord = {X = 0, Y = -300, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=4,Y=.1,Z=2.3}}
prefab[2] = { Component = "ButtonComponent", OverLayName ="GameUI", Active = true, 
				ContainerName = "GameUI/RedCard", DefaultMaterial ="CallOfCooking/attackBase", HoverMaterial = "CallOfCooking/attackHover", PressMaterial = "CallOfCooking/attackPress"}
prefab[3] = { Component = "AttackSpeedCardComponent"}