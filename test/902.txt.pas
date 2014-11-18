var
	cdn:array[#0..#127]of longint;
	n,m,mode:longint;
	st,tmp:string;
	dt:array[0..2000]of string;
	procedure init;
		var
			i:longint;
		begin
                        //fillchar(dt,sizeof(dt),0);
			readln(sT);
			for i:=1 to 26{length(st)}do
				cdn[st[i]]:=i;
			readln(n);
			for i:=1 to n do
				readln(dt[i]);
                                //cdn[#0]:=-maxint;
		end;
	function big(const a,b:longint):boolean;
		var
			i,j:longint;
		begin
			j:=length(dt[a]);
			i:=length(dt[b]);
			if i<j then j:=i;
			for i:=1 to j do
				if cdn[dt[a,i]]>cdn[dt[b,i]]then
					exit(true)
				else if cdn[dt[a,i]]<cdn[dt[b,i]]then
					exit(false);
                        if i=length(dt[a])then exit(false)
                        else if i=length(dt[b])then exit(true) else
			{i:=0;
			repeat
				inc(i);
			until (dt[a,i]<>dt[b,i])or(i=length(dt[a]))or(i=length(dt[b]));
			if i=length(dt[a])then exit(false)
			else if i=length(dt[b])then exit(true)
			else if dt[a,i]>dt[b,i]then
				exit(true);}
			exit(false);
		end;
	procedure work;
		var
			i,j,x:longint;
		begin
			for i:=1 to n-1 do
				begin
					x:=i;
					for j:=i+1 to n do //begin
                                        {if (i=474)and(dt[j]='abbbbabbba')then
                                        writeln('short',j)
                                        else if (i=474)and(dt[j]=
                                        'abbbbabbbaaabbababbabbbbabbbbbabaaababbabbabbabbabbabbbbbaabbbabbaaaaabbbabaabbabbbabbaaabbab')then
                                        writeln('long:',j);  }
						if big(x,j)then
							x:=j;
                                        //end;
					tmp:=dt[x];dt[x]:=dt[i];dt[i]:=tmp;
				end;
			readln(mode);
			if mode=1 then
				for i:=1 to n do
					writeln(dt[i])
				else for i:=n downto 1 do
					writeln(dt[i]);
		end;
	begin      //st:='a';writeln(ord(st[10]));

		init;
		work;

	end.


