open ReactNative;
open ReactNavigation;
open DiscussionStyle;
module Discussion ={
  type comment = {
  .
  "message": string,
  "createdAt": string,
  "createdBy": string,
};
// type listCommentsByTalkId = {. "items":array(comment)};

type state = {
  .
  "comments": array(comment),
  "loading": bool,
};
type gqlResp = {. "data": state};

type response = {. "data": state};
external toApolloResult: 'a => response = "%identity";
// let talkId = "d4447477-20fc-4a48-a97f-edfb486b5d6a";
// let deviceId = "device-fake-id";
// let width = dimensions##width;
// type params = Js.t({.});
// type navigation = {. "state": params};
let deviceId = Expo.Constants.deviceId;
// let deviceId = "Expo.Constants.deviceId";
let width = dimensions##width;
[@react.component]
let make =
    (
      ~comments: array(ListCommentsQuery.item),
      ~navigation: Navigation.t,
      ~client,
    ) => {
  let (message, setMessage) = React.useState(() => "");
  let (comments, setComments) = React.useState(() => comments);
  let (appState, setAppState) = React.useState(_ => AppState.currentState);
  let (subscribed, setSubscribed) = React.useState(_ => false);
  // let (username, setUsername) = React.useState(() => "");
  let handleChangeText = message => {
    setMessage(message);
  };
  Js.log2("deviceId", deviceId);
  // let initialComments = comments -> Belt.SortArray.stableSortBy((a1, a2) => compare(a1##createdAt, a2##createdAt))->Belt.Array.reverse;
  // setComments(_=>initialComments);
  // React.useEffect(() => {

  //     Js.log2("initialComments: ", initialComments)
  //   setComments(_=> initialComments)
  //   // handleAppStateChange(appState);
  //   None;
  // });
  // let params = navigation##state##params;
  let talkId = "navigation##state##params##id";

  let handleSetComments = newItem => {
    let newCommentsArray = Array.append([|newItem|], comments);
    let sorted = newCommentsArray |> Js.Array.sortInPlace;
    let sortedTracks =
      newCommentsArray
      ->Belt.SortArray.stableSortBy((a1, a2) =>
          compare(a1##createdAt, a2##createdAt)
        )
      ->Belt.Array.reverse;
    // Js.log2("NEW_ARRAY: ", newCommentsArray);
    Js.log2("sorted: ", sorted[0]);
    Js.log2("newCommentsArray: ", newCommentsArray[0]);
    Js.log2("sortedTracks: ", sortedTracks[0]);
    setComments(_ => sortedTracks);
  };
  let newComment = (): CreateComment.comment => {
    "createdAt": Some(Js.Date.now()->Js.Float.toString),
    "id": None,
    "talkId": Some(talkId),
    "message": Some(message),
    "createdBy": Some(UserSession.getName()),
    "deviceId": Some(deviceId),
  };
  let dataComment =
      (
        ~message: option(string),
        ~createdAt: option(string),
        ~createdBy: option(string),
      )
      : ListCommentsQuery.item => {
    "message": message,
    "createdAt": createdAt,
    "createdBy": createdBy,
  };
  let subscription = () =>
    AppState.addEventListener(
      `change(
        event =>
          event === AppState.active
            ? {
              Js.log("do something that returns unit");
              setSubscribed(_ => true);
            }
            : setSubscribed(_ => false),
      ),
    );
  // let listCommentsSubcription = () => {
  //   let gqlSubscription = Subscriptions.OnCreateComment.make(~talkId, ());

  //   let gqlSubscriptionStr = gqlSubscription##query;
  //   let queryConfig = {
  //     "query": ApolloClient.gql(. gqlSubscriptionStr),
  //     "variables": gqlSubscription##variables,
  //   };
  //   Js.log2("COMMENT_MUTATION_gqlSubscriptionStr", gqlSubscriptionStr);
  //   // Js.log2("COMMENT_MUTATION", queryConfig##mutation);
  //   let apolloData = client##mutate(queryConfig);
  //   apolloData
  //   |> Js.Promise.then_(gqlResp => {
  //        let resp = toApolloResult(gqlResp);
  //        Js.log2("COMMENT_MUTATION_RESPONSE: ", resp);

  //        Js.Promise.resolve();
  //      })
  //   |> ignore;
  // };
  let handleAppStateChange = nextAppState => {
    switch (appState, nextAppState) {
    | (_, state) when state === AppState.background =>
      Js.log("App has come to the background!")
    | (_, state) when state === AppState.active => setSubscribed(_ => true)
    | _ => ()
    };
    setAppState(_ => nextAppState);
  };
  // let netInfoChange = state => {
  //   switch (state) {
  //   | true =>
  //     Js.log("NetInfo.IsConnected!");
  //     listCommentsSubcription();
  //   | _ => Js.log("NetInfo Is_NOT_Connected!")
  //   };
  // };

  // React.useEffect(() => {
  //   AppState.addEventListener(`change(state => handleAppStateChange(state)))
  //   |> ignore;
  //   // NetInfo.IsConnected.fetch()
  //   // |> Js.Promise.then_(response => {
  //   //      Js.log2("NetInfo.IsConnected!", response);
  //   //     //  netInfoChange(response);
  //   //      setSubscribed(_ => response)|> ignore;
  //   //      Js.Promise.resolve();
  //   //    })
  //   // |> ignore;
  //   // NetInfo.addEventListener(`connectionChange(state => netInfoChange(state)))
  //   // |>ignore;
  //   Some(
  //     () =>
  //       AppState.removeEventListener(
  //         `change(state => handleAppStateChange(state)),
  //       ),
  //   );
  // });

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
      // {(subscribed === true)
      // change to `appState === AppState.background` to see this div not render

        {appState === AppState.active
           ? <OnCreateCommentSub talkId deviceId>
               ...{children => {
                 let createdAt =
                   [%get_in children#??createdAt]
                   ->Belt.Option.getWithDefault("");
                 let createdBy =
                   [%get_in children#??createdBy]
                   ->Belt.Option.getWithDefault("");
                 let message =
                   [%get_in children#??message]
                   ->Belt.Option.getWithDefault("");
                 //  dataComment(
                 //    ~message=Some(message),
                 //    ~createdAt=Some(createdAt),
                 //    ~createdBy=Some(createdBy),
                 //  )
                 //  ->handleSetComments;
                 let child =
                   CreateComment.dataComment(
                     ~message=Some(message),
                     ~createdAt=Some(createdAt),
                     ~createdBy=Some(createdBy),
                   );
                 child->Js.Json.stringifyAny |> Belt.Option.getExn |> ignore;

                 Js.log2("CHILDREN: ", children);
                 Js.log2("CHILDREN: ", child);
               }}
             </OnCreateCommentSub>
           : React.null}
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
};};
[@react.component]
  let make = (~navigation) => {
    <ApolloConsumer>
      {client =>
         <ListCommentsQuery>
           {data => {
              let comments = data;
              <Discussion comments navigation client />;
            }}
         </ListCommentsQuery>}
    </ApolloConsumer>;
  };
  make->NavigationOptions.(setNavigationOptions(t(~title="Discussion", ())));