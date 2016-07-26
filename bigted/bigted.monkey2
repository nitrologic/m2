		
#Import "mojox/mojox"

#Import "mainwindow"
#Import "projectview"
#Import "debugview"
#Import "helpview"
#Import "finddialog"
#Import "searchdialog"

#Import "ted2document"
#Import "txtdocument"
#Import "mx2document"
#Import "mx2highlighter"
#Import "imgdocument"

Namespace ted2

Using std..
Using mojo..
Using mojox..

Function Main()

	ChangeDir(AppDir())

	Print "BigTed@"+CurrentDir()+" assets:"+AssetsDir()

	New AppInstance
	
	Theme.Load("bin/bigted.style.json")
 
	new MainWindowInstance( "BigTed",New Recti( 0,0,800,600 ),WindowFlags.Resizable|WindowFlags.Center )
		
	App.Run()
End
