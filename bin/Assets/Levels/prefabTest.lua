go_0 = {}
go_0[0] = { Name = "Lemon_"}
go_0[1] = { Component = "Transform", Coord = {X = 0, Y = -300, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=4,Y=.1,Z=2.3}}
go_0[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Brown", 
			LookAt ={X=1, Y=1, Z=1},
			Visible=true, Shadows=true, RenderingDistance = 9999}
go_0[3] = { Component = "BoxCollider", Type="Box",Width=1000,Height=1,Depth=1000,IsTrigger=false}
go_0[4] = { Component = "RigidBody", Type="Box", Mass=9, Width=40, Depth=0, Height=40, ConstrainAngle = true,
			Bounciness=1,kinematic=true,IsTrigger=false}