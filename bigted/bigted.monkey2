
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

	New AppInstance
	
	Theme.Load()
	
	New BigTed
		
	App.Run()
End

Class BigTed Extends MainWindowInstance

	Method New()
		Super.New( "BigTed",New Recti( 256,128,800,600 ),WindowFlags.Resizable|WindowFlags.Center )

		local monkey2dir:=RealPath(_mx2cc)

		Print monkey2dir

			
		While GetFileType( "bin" )<>FileType.Directory Or GetFileType( "modules" )<>FileType.Directory
	
			Print "CurrentDir="+CurrentDir()			
			
			If IsRootDir( CurrentDir() )
				Print "Error initializing BigTed - can't find working dir!"
				libc.exit_( -1 )
			Endif
			
			ChangeDir( ExtractDir( CurrentDir() ) )
			
		Wend
	end

End
