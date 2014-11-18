program vijos1143;
var n,i,j,k,s:longint;
    a:array[0..40,0..20,0..20,0..20] of longint;
    map:array[0..20,0..20] of longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
      read(map[i,j]);
    readln;
  end;
  fillchar(a,sizeof(a),0);
  for s:=1 to n*2-1 do
    for i:=1 to n do
      for j:=1 to n do
        for k:=1 to n do
        begin
          if (i>s)or(j>s)or(k>s) then break;
          a[s,i,j,k]:=0;
          if a[s-1,i,j,k]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i,j,k];
          if a[s-1,i-1,j,k]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i-1,j,k];
          if a[s-1,i-1,j,k-1]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i-1,j,k-1];
          if a[s-1,i-1,j-1,k]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i-1,j-1,k];
          if a[s-1,i-1,j-1,k-1]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i-1,j-1,k-1];
          if a[s-1,i,j,k-1]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i,j,k-1];
          if a[s-1,i,j-1,k]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i,j-1,k];
          if a[s-1,i,j-1,k-1]>a[s,i,j,k] then a[s,i,j,k]:=a[s-1,i,j-1,k-1];
          a[s,i,j,k]:=a[s,i,j,k]+map[i,s-i+1];
          if j<>i then a[s,i,j,k]:=a[s,i,j,k]+map[j,s-j+1];
          if (k<>i)and(k<>j) then a[s,i,j,k]:=a[s,i,j,k]+map[k,s-k+1];
        end;
  writeln(a[n*2-1,n,n,n]);
end.
