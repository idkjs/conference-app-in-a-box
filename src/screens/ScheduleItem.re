open ReactNative;
// open ReactNavigation;
open ScheduleStyle;

[@react.component]
let make = (~talk: TalkType.t, ~onPress) =>
  <>
    <TouchableOpacity onPress>
      <View style=styles##talk>
        <View style=styles##speakerContainer>
          <View style=styles##avatarContainer>
            {talk##speakerAvatar
             ->Belt.Option.map(speakerAvatar =>
                 <Image
                   style=styles##avatar
                   resizeMode=`cover
                   source={Image.Source.fromUriSource(
                     Image.uriSource(~uri=speakerAvatar, ()),
                   )}
                 />
               )
             ->Belt.Option.getWithDefault(React.null)}
          </View>
          <View style=styles##infoContainer>
            <Text style=styles##name> {talk##name |> React.string} </Text>
            <Text style=styles##speakerName>
              {talk##speakerName |> React.string}
            </Text>
          </View>
        </View>
        <View style=styles##timeContainer>
          {talk##time
           ->Belt.Option.map(time =>
               <Text style=styles##talkTime> {time |> React.string} </Text>
             )
           ->Belt.Option.getWithDefault(React.null)}
        </View>
      </View>
    </TouchableOpacity>
  </>;