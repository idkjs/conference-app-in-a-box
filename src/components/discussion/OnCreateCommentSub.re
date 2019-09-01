open ReactNative;
open DiscussionStyle;

type onCreateCommentWithId =
  option({
    .
    "createdAt": option(string),
    "createdBy": option(string),
    "deviceId": option(string),
    "id": string,
    "message": option(string),
    "talk":
      option({
        .
        "comments": option({. "nextToken": option(string)}),
        "github": option(string),
        "id": string,
        "location": option(string),
        "name": string,
        "speakerBio": string,
        "speakerName": string,
        "summary": string,
        "time": option(string),
        "twitter": option(string),
      }),
    "talkId": option(string),
  });
[@react.component]
let make = (~children, ~talkId, ~deviceId) => {
  let subMutation = Subscriptions.OnCreateComment.make(~talkId, ());
  let variables = subMutation##variables;
  <Subscriptions.OnCreateCommentSubscription variables>
    ...{({result}) =>
      <View>
        {switch (result) {
         | Error(error) =>
           Js.Console.error(error);

           <Text style=styles##message> {ReasonReact.string("Error")} </Text>;

         | Data(data) =>
           let onCreateCommentWithId: onCreateCommentWithId =
             data##onCreateCommentWithId;
           Js.log2("onCreateCommentWithId: ", onCreateCommentWithId);
           let commentDeviceId =
             [%get_in onCreateCommentWithId#??deviceId]
             ->Belt.Option.getWithDefault("");
           Js.log2("deviceId", deviceId);
           Js.log2("commentDeviceId", commentDeviceId);
           Js.log2(
             "comment##deviceId === deviceId",
             commentDeviceId === deviceId,
           );
           commentDeviceId === deviceId
             ? children(onCreateCommentWithId): ()|>ignore;
           <Text style=styles##message>
             {ReasonReact.string("CHECK Console")}
           </Text>;
         | Loading =>
           <Text style=styles##message>
             {ReasonReact.string("Type a new message")}
           </Text>
         }}
      </View>
    }
  </Subscriptions.OnCreateCommentSubscription>;
};