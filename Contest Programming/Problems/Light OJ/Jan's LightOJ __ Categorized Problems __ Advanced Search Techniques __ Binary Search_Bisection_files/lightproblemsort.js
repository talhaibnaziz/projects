function toggleShow( tableId ) {
	if( document.getElementById('reportName').innerHTML == "(show unsolved)" ) {
		document.getElementById('reportName').innerHTML = "(show all)";
		
		var table = document.getElementById(tableId);
		var tableRows = table.getElementsByTagName('tr');

		for( var i = 1; i < tableRows.length; i++ ) {
			var tableCols = tableRows[i].getElementsByTagName('th');			
			var tableLink = tableCols[0].getElementsByTagName('a');
			if( tableLink[0].innerHTML.substr(26, 6) == "solved" ) {
				tableRows[i].style.display = "none";
			}
		}
	}
	else {
		document.getElementById('reportName').innerHTML = "(show unsolved)";
		
		var table = document.getElementById(tableId);
		var tableRows = table.getElementsByTagName('tr');

		for( var i = 1; i < tableRows.length; i++ ) {
			tableRows[i].style.display = "";
		}
	}
	
	alternateTable( tableId );
}

function alternateTable( tableId ) {
	var table = document.getElementById(tableId);
	var tableRows = table.getElementsByTagName('tr');

	var curClass = "newone";

	for( var i = 1; i < tableRows.length; i++ ) {
		if( tableRows[i].style.display != "none" ) {
			tableRows[i].className = curClass;
			var tableCols = tableRows[i].getElementsByTagName('th');
			
			tableCols[0].className = curClass;
			
			tableCols = tableRows[i].getElementsByTagName('td');
			for( var j = 0; j < tableCols.length; j++ ) {
				tableCols[j].className = curClass;
				if( j == 2 ) {
					tableCols[j].className = curClass + "Left";
				}
				tableLink = tableCols[j].getElementsByTagName('a');
				if( tableLink.length > 0 ) {
					tableLink[0].className = "user_link_" + curClass;
				}
			}
			
			if( curClass == "newone" ) {
				curClass = "newtwo";
			}
			else {
				curClass = "newone";
			}
		}
	}
}

function compareByNameASC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var p = tableColsA[2].getElementsByTagName('a');
	var q = tableColsB[2].getElementsByTagName('a');
	
	var x = p[0].innerHTML.toLowerCase();
	var y = q[0].innerHTML.toLowerCase();
	
	return ((x < y) ? -1 : ((x > y) ? 1 : 0));
}

function compareByNameDESC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var p = tableColsA[2].getElementsByTagName('a');
	var q = tableColsB[2].getElementsByTagName('a');
	
	var x = p[0].innerHTML.toLowerCase();
	var y = q[0].innerHTML.toLowerCase();
	
	return ((x < y) ? 1 : ((x > y) ? -1 : 0));
}

function compareByIdASC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var p = tableColsA[1].getElementsByTagName('a');
	var q = tableColsB[1].getElementsByTagName('a');
	
	var x = parseInt( p[0].innerHTML );
	var y = parseInt( q[0].innerHTML );
	
	return ((x < y) ? -1 : ((x > y) ? 1 : 0));
}

function compareByIdDESC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var p = tableColsA[1].getElementsByTagName('a');
	var q = tableColsB[1].getElementsByTagName('a');
	
	var x = parseInt( p[0].innerHTML );
	var y = parseInt( q[0].innerHTML );
	
	return ((x < y) ? 1 : ((x > y) ? -1 : 0));
}

function compareBySolvedTriedASC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var c = tableColsA[3].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	var d = tableColsB[3].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	
	var c1 = c.split( "/" );
	var c3 = parseInt( c1[0] );
	var c4 = parseInt( c1[1] );
	
	var d1 = d.split( "/" );
	var d3 = parseInt( d1[0] );
	var d4 = parseInt( d1[1] );
	
	var x = c3 * d4;
	var y = c4 * d3;
	
	if( !x && !y ) {
		return ((c3 < d3) ? -1 : ((c3 > d3) ? 1 : 0));
	}
	
	return ((x < y) ? -1 : ((x > y) ? 1 : c3 - d3));
}

function compareBySolvedTriedDESC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var c = tableColsA[3].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	var d = tableColsB[3].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	
	var c1 = c.split( "/" );
	var c3 = parseInt( c1[0] );
	var c4 = parseInt( c1[1] );
	
	var d1 = d.split( "/" );
	var d3 = parseInt( d1[0] );
	var d4 = parseInt( d1[1] );
	
	var x = c3 * d4;
	var y = c4 * d3;
	
	if( !x && !y ) {
		return ((c3 < d3) ? 1 : ((c3 > d3) ? -1 : 0));
	}
	
	return ((x < y) ? 1 : ((x > y) ? -1 : d3 - c3));
}

function compareByAcTotalASC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var c = tableColsA[4].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	var d = tableColsB[4].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	
	var c1 = c.split( "/" );
	var c3 = parseInt( c1[0] );
	var c4 = parseInt( c1[1] );
	
	var d1 = d.split( "/" );
	var d3 = parseInt( d1[0] );
	var d4 = parseInt( d1[1] );
	
	var x = c3 * d4;
	var y = c4 * d3;
	
	if( !x && !y ) {
		return ((c3 < d3) ? -1 : ((c3 > d3) ? 1 : 0));
	}
	
	return ((x < y) ? -1 : ((x > y) ? 1 : c3 - d3));
}

function compareByAcTotalDESC( a, b ) {
	var tableColsA = a.getElementsByTagName('td');
	var tableColsB = b.getElementsByTagName('td');
	
	var c = tableColsA[4].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	var d = tableColsB[4].getElementsByTagName('a')[0].getElementsByTagName('span')[0].getElementsByTagName('div')[1].innerHTML;
	
	var c1 = c.split( "/" );
	var c3 = parseInt( c1[0] );
	var c4 = parseInt( c1[1] );
	
	var d1 = d.split( "/" );
	var d3 = parseInt( d1[0] );
	var d4 = parseInt( d1[1] );
	
	var x = c3 * d4;
	var y = c4 * d3;
	
	if( !x && !y ) {
		return ((c3 < d3) ? 1 : ((c3 > d3) ? -1 : 0));
	}
	
	return ((x < y) ? 1 : ((x > y) ? -1 : d3 - c3));
}

function sortTable( tableId, fieldName ) {
	var table = document.getElementById(tableId);
	var tableRows = table.getElementsByTagName('tr');
	
	var allInfo = new Array();
	for( var i = 1; i < tableRows.length; i++ ) {
		allInfo[i-1] = tableRows[i];
	}
	
	var flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	if( fieldName == "problemName" ) {
		flag2 = 1;
		if( document.getElementById('sortImageName').title == "Sort Descending" ) {
			allInfo.sort( compareByNameDESC );
			document.getElementById('sortImageName').title = "Sort Ascending";
			document.getElementById('sortImageName').src = "images/sort_desc.png";
		}
		else {
			allInfo.sort( compareByNameASC );
			document.getElementById('sortImageName').title = "Sort Descending";
			document.getElementById('sortImageName').src = "images/sort_asc.png";
		}
	}
	else if( fieldName == "problemId" ) {
		flag1 = 1;
		if( document.getElementById('sortImageId').title == "Sort Descending" ) {
			allInfo.sort( compareByIdDESC );
			document.getElementById('sortImageId').title = "Sort Ascending";
			document.getElementById('sortImageId').src = "images/sort_desc.png";
		}
		else {
			allInfo.sort( compareByIdASC );
			document.getElementById('sortImageId').title = "Sort Descending";
			document.getElementById('sortImageId').src = "images/sort_asc.png";
		}
	}
	else if( fieldName == "solvedTried" ) {
		flag3 = 1;
		if( document.getElementById('sortSolvedTried').title == "Sort Descending" ) {
			allInfo.sort( compareBySolvedTriedDESC );
			document.getElementById('sortSolvedTried').title = "Sort Ascending";
			document.getElementById('sortSolvedTried').src = "images/sort_desc.png";
		}
		else {
			allInfo.sort( compareBySolvedTriedASC );
			document.getElementById('sortSolvedTried').title = "Sort Descending";
			document.getElementById('sortSolvedTried').src = "images/sort_asc.png";
		}
	}
	else if( fieldName == "acTotal" ) {
		flag4 = 1;
		if( document.getElementById('sortAcTotal').title == "Sort Descending" ) {
			allInfo.sort( compareByAcTotalDESC );
			document.getElementById('sortAcTotal').title = "Sort Ascending";
			document.getElementById('sortAcTotal').src = "images/sort_desc.png";
		}
		else {
			allInfo.sort( compareByAcTotalASC );
			document.getElementById('sortAcTotal').title = "Sort Descending";
			document.getElementById('sortAcTotal').src = "images/sort_asc.png";
		}
	}
	if( !flag1 ) {
		document.getElementById('sortImageId').title = "Sort Ascending";
		document.getElementById('sortImageId').src = "images/sort_both.png";
	}
	if( !flag2 ) {
		document.getElementById('sortImageName').title = "Sort Ascending";
		document.getElementById('sortImageName').src = "images/sort_both.png";
	}
	if( !flag3 ) {
		document.getElementById('sortSolvedTried').title = "Sort Ascending";
		document.getElementById('sortSolvedTried').src = "images/sort_both.png";
	}
	if( !flag4 ) {
		document.getElementById('sortAcTotal').title = "Sort Ascending";
		document.getElementById('sortAcTotal').src = "images/sort_both.png";
	}
	
	var temp = new Array();
	var temp2 = new Array();
	for( var i = 0; i < allInfo.length; i++ ) {
		temp[i] = allInfo[i].innerHTML;
		temp2[i] = allInfo[i].style.display;
	}
	
	for( var i = 1; i < tableRows.length; i++ ) {
		tableRows[i].innerHTML = temp[i-1];
		tableRows[i].style.display = temp2[i-1];
	}
	alternateTable( tableId );
}
