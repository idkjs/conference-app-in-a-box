open ReactNative;
open ReactNavigation;
open TalkStyles;
[@react.component]
let make = (~navigation: Navigation.t) => {
  let getTalk: Js.nullable(TalkType.t) =
    navigation->Navigation.getParam("talk");

  let talk = TalkType.talkJson(getTalk);

  <ScrollView>
    <View style=styles##container>
      {switch (talk.speakerAvatar) {
       | Some(uri) =>
         <Image
           source={Image.Source.fromUriSource(Image.uriSource(~uri, ()))}
           resizeMode=`cover
           style=styles##avatar
         />
       | None => React.null
       }}
      <Text style=styles##name> {talk.name |> React.string} </Text>
      <Text style=styles##speakerName>
        {talk.speakerName |> React.string}
      </Text>
      {switch (talk.time) {
       | Some(time) =>
         <Text style=styles##time> {time |> React.string} </Text>
       | None => React.null
       }}
      <Text style=styles##title> {"Summary" |> React.string} </Text>
      <Text style=styles##summary> {talk.summary |> React.string} </Text>
      <Text style=styles##title> {"Bio" |> React.string} </Text>
      <Text style=styles##speakerBio> {talk.speakerBio |> React.string} </Text>
    </View>
  </ScrollView>;
};
// make->NavigationOptions.setDynamicNavigationOptions(params => {
//   let navigation = params##navigation;
//   let navigation = params##navigation;
//             let title =
//               navigation
//               ->Navigation.getParam("title")
//               ->Js.Nullable.toOption
//               ->Belt.Option.mapWithDefault("Talk", t => t##name);
//   let navigationOptions = params##navigationOptions;
//   let state = Utils.unsafeCast(navigationOptions)##state;
//   Js.log2("DETAIL_navigationOptions", navigationOptions);
//   Js.log2("DETAIL_navigationOptions##state", state);
//   // let title = navigation->Navigation.getParam("talk");
//   let getTalk: Js.nullable(TalkType.t) =
//     navigation->Navigation.getParam("talk");

//   let talk = TalkType.talkJson(getTalk);
//   Js.log2("TALK_TITLE", talk.name);
//   Js.log2("TALK_TITLE", title);
//   // let title =
//   //     navigation->Navigation.getParamWithDefault(
//   //       "talk",
//   //       "A Nested Details Screen",
//   //     );
//    NavigationOptions.t(
//       ~title,
//       (),
//     );
// });