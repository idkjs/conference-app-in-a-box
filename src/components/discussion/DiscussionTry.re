open ReactNative;
open DiscussionStyle;

// let talkId = "d4447477-20fc-4a48-a97f-edfb486b5d6a";
// let deviceId = "device-fake-id";
// let width = dimensions##width;
type params = Js.t({.});
type navigation = {. "state": params};
// let deviceId = Expo.Constants.deviceId;
let deviceId = "Expo.Constants.deviceId";
let width = dimensions##width;
[@react.component]
let make = (~comments: array(ListCommentsQuery.item),~navigation) => {
  let (message, setMessage) = React.useState(() => "");
  let (comments, setComments) = React.useState(() => comments);
    let (appState, setAppState) = React.useState(_ => AppState.currentState);

  let handleChangeText = message => {
    setMessage(message);
  };
  let talkId = navigation##state##params##id;
  let handleSetComments = newItem => {
    let newCommentsArray = Array.append([|newItem|], comments);
    Js.log2("NEW_ARRAY: ", newCommentsArray);
    setComments(_ => newCommentsArray);
  };
  let newComment = (): CreateComment.comment => {
    "createdAt": Some(Js.Date.now()->Js.Float.toString),
    "id": None,
    "talkId": Some(talkId),
    "message": Some(message),
    "createdBy": Some(UserSession.getName()),
    "deviceId": Some(deviceId),
  };
   let renderAppState =
    switch (appState) {
    | appState when appState === AppState.active => "active"
    | appState when appState === AppState.background => "background"
    | appState when appState === AppState.inactive => "inactive"
    | _ => "unknown"
    };
  <React.Fragment>
    <View style=styles##comment>
      <Text style=styles##message> {message |> React.string} </Text>
    </View>
    <View style=styles##comment>
      <Text style=styles##message>
        {"Current state is: " ++ renderAppState |> React.string}
      </Text>
    </View>
    <View style=styles##comment>
      <OnCreateCommentSub talkId deviceId>
             ...{children => {
               let createdAt =
                 [%get_in children#??createdAt]
                 ->Belt.Option.getWithDefault("");
               let createdBy =
                 [%get_in children#??createdBy]
                 ->Belt.Option.getWithDefault("");
               let message =
                 [%get_in children#??message]->Belt.Option.getWithDefault("");
               let child = CreateComment.dataComment(
                 ~message=Some(message),
                 ~createdAt=Some(createdAt),
                 ~createdBy=Some(createdBy),
               );
               child->Js.Json.stringifyAny|>Belt.Option.getExn|>ignore;

               Js.log2("CHILDREN: ", children);
               Js.log2("CHILD: ", child);
      //          <Text style=styles##message>
      //   {"Current state is: " ++ message  |> React.string}
      // </Text>
             }}
           </OnCreateCommentSub>
    </View>
    <KeyboardAvoidingView
      accessibilityViewIsModal=true
      keyboardVerticalOffset=130.
      behavior=`padding
      style=styles##container>
      <View style=styles##scrollViewContainer>
        <ScrollView>
          {!(Array.length(comments) > 0)
             ? <View style=styles##comment>
                 <Text style=styles##message>
                   {"No comments yet!" |> React.string}
                 </Text>
               </View>
             : React.null}
          {comments->Belt.Array.mapWithIndex((idx, c: ListCommentsQuery.item) =>
             <View key={string_of_int(idx)} style=styles##comment>
               <Text style=styles##message>
                 {c##message
                  ->Belt.Option.map(message =>
                      "message: " ++ message |> React.string
                    )
                  ->Belt.Option.getWithDefault(React.null)}
               </Text>
               <Text style=styles##createdBy>
                 {c##createdBy
                  ->Belt.Option.map(createdBy =>
                      "createdBy: " ++ createdBy |> React.string
                    )
                  ->Belt.Option.getWithDefault(React.null)}
               </Text>
             </View>
           )
           |> React.array}
        </ScrollView>
      </View>
      <CreateComment
        message
        handleChangeText
        handleSetComments
        input={newComment()}
      />
    </KeyboardAvoidingView>
  </React.Fragment>;
};