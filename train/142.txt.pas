type
  number=array[0..300] of longint;

var
  s1,cs:number;
  n,n3,n2:longint;

  procedure inte;
    var yu:longint;
    begin
      readln( n );
      if n<=4 then
        begin
          if n=4 then writeln( 4 );
          if n=3 then writeln( 3 );
          if n=2 then writeln( 2 );
          if n=1 then writeln( 1 );
          halt;
        end;
      n3:= n div 3;
      yu:= n mod 3;
      if yu=1 then begin dec( n3 ); n2:=2; end
              else
                if yu=2 then begin n2:=1; end
                        else begin n2:=0; end;
    end;

  function cheng( a,b:number ):number;
    var i,j,x:longint;
    begin
      fillchar( cheng,sizeof(cheng),0 );
      for i:=1 to a[0] do
        begin
          x:=0;
          for j:=1 to b[0] do
            begin
              x:= a[i]*b[j] + x div 10 + cheng[i+j-1];
              cheng[i+j-1]:=x mod 10;
            end;
          cheng[i+j]:=x div 10;
        end;
      cheng[0]:= i+j;
      while (  cheng[ cheng[0] ]=0 )and(cheng[0]>1) do dec( cheng[0] );
    end;

  procedure main;
    var i:longint;
    begin
      s1[0]:=1; s1[1]:=3;
      cs[0]:=1; cs[1]:=3;
      for i:=1 to n3-1 do s1:=cheng( s1 , cs );
      cs[0]:=1; cs[1]:=2;
      for i:=1 to n2 do s1:=cheng( s1 , cs );
    end;

  procedure print;
    var i:longint;
    begin
      for i:=s1[0] downto 1 do write( s1[i] );
    end;

begin
  inte;
  main;
  print;
end.

