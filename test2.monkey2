#Import "<std>"
#Import "<mojo>"
#Import "<steamworks>"

Using std..
Using mojo..
Using steamworks..

Class SteamApp Extends Window
	
	Method New()

		Local haveSteam := SteamAPI_Init()
	   
		If Not haveSteam
			Print "SteamAPI_Init failed, is steam running and steam_appid.txt file attached?"
			Return
		Endif
		
		
		Print "SteamAPI_Init returned "+haveSteam
		
		Local loggedOn := SteamUser().BLoggedOn()
		
		Print "SteamUser()->BLoggedOn() returned "+loggedOn
	
	
	'	// valid options are "Friends", "Community", "Players", "Settings", "OfficialGameGroup", "Stats", "Achievements"
	
		SteamFriends().ActivateGameOverlay( "Friends" )
	End
	
	Method shutdown()
	
		SteamAPI_Shutdown()
	End

	Method OnRender( canvas:Canvas ) Override
	
		App.RequestRender()
	
		Const timeStep:=1.0/60.0
		
	End

	
End

Function Main()
	New AppInstance
	
	New SteamApp
	
	App.Run()
End


