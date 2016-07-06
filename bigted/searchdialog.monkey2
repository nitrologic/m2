
Namespace ted2

Class SearchDialog Extends Dialog

	Method New()
	
		_searchField=New TextField		
		_resultsField=New TextField
		
		_searchField.EnterHit=MainWindow.OnFindNext
		_searchField.TabHit=Lambda()
			_resultsField.MakeKeyView()
			_resultsField.SelectAll()
		End

		_resultsField.EnterHit=MainWindow.OnFindNext
		_resultsField.TabHit=Lambda()
			_searchField.MakeKeyView()
			_searchField.SelectAll()
		End
		
		_caseSensitive=New Button( "Case sensitive: " )
		_caseSensitive.Checkable=True
		
		_escapedText=New Button( "Escaped text: ")
		_escapedText.Checkable=True
		
		Local search:=New DockingView
		search.AddView( New Label( "Search:" ),"left",80,False )
		search.ContentView=_searchField
		
		Local results:=New DockingView
		results.AddView( New TextView(),"top" )
		results.ContentView=_resultsField
		
		_docker=New DockingView
		_docker.AddView( search,"top" )
		_docker.AddView( results,"top" )
		_docker.AddView( _caseSensitive,"top" )
'		_docker.AddView( _escapedText,"top" )
		_docker.AddView( New Label( " " ),"top" )
		
		Title="Search/Replace"
		
		MaxSize=New Vec2i( 512,0 )
		
		ContentView=_docker
		
'		AddAction( MainWindow._searchNext )		
'		AddAction( MainWindow._searchPrevious )
'		AddAction( MainWindow._searchReplace )
'		AddAction( MainWindow._searchReplaceAll )
		
		AddAction( "Close" ).Triggered=Lambda()
			Close()
			MainWindow.UpdateKeyView()
		End

		Opened=Lambda()
			_searchField.MakeKeyView()
			_searchField.SelectAll()
		End

	End
	
	Property FindText:String()
	
		Return _searchField.Text
	End
	
	Property CaseSensitive:Bool()
	
		Return _caseSensitive.Checked
	End
	
	Private
	
	Field _searchField:TextField
	Field _resultsField:TextField
	Field _caseSensitive:Button
	Field _escapedText:Button

	Field _docker:DockingView

End
